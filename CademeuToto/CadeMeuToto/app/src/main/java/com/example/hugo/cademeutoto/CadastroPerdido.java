package com.example.hugo.cademeutoto;

import android.Manifest;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.provider.MediaStore;
import android.support.annotation.NonNull;
import android.support.constraint.ConstraintLayout;
import android.support.design.widget.Snackbar;
import android.support.v4.app.ActivityCompat;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.Toast;

import com.example.hugo.cademeutoto.database.Dados;
import com.example.hugo.cademeutoto.dominio.entidades.Perdidos;
import com.example.hugo.cademeutoto.dominio.repositorio.PerdidosRepositorio;

public class CadastroPerdido extends AppCompatActivity
{
    private ImageButton imageButton;    // Adiciona a imagem do animal
    private Button btnMostreOnde;       // Mostre onde perdeu o Pet

    private EditText edtNome;
    private Button btnIdade;
    private Button btnRaca;
    private EditText edtCorPelo;
    private EditText edtDetalhes;
    private Button btnTipoAnimal;
    private ConstraintLayout layoutCadPer;

    public String idade = null;
    public String raca = null;
    public String tipo_animal = null;

    private ImageView imagem;
    private final int GALERIA = 1;
    private final int PERMISSAO_REQUEST = 2;

    private SQLiteDatabase conexao;
    private Dados dados;

    private PerdidosRepositorio perdidosRepositorio;
    private Perdidos perdido;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cadastro_perdido);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);

        if(ContextCompat.checkSelfPermission(this,Manifest.permission.READ_EXTERNAL_STORAGE)
                !=  PackageManager.PERMISSION_GRANTED)
        {
            if(ActivityCompat.shouldShowRequestPermissionRationale(this,
                    Manifest.permission.READ_EXTERNAL_STORAGE))
            {}else
            {
                ActivityCompat.requestPermissions(this,
                        new String[]{Manifest.permission.READ_EXTERNAL_STORAGE},
                        PERMISSAO_REQUEST);
            }
        }

        imageButton = (ImageButton)findViewById(R.id.btnimage);     // Adiciona a imagem do animal
        btnMostreOnde = (Button)findViewById(R.id.btnMostreOnde);  // Mostre onde perdeu o Pet

        layoutCadPer = (ConstraintLayout)findViewById(R.id.layoutCadPer);

        edtNome = (EditText)findViewById(R.id.edtNome);
        edtCorPelo = (EditText)findViewById(R.id.edtCorPelo);
        btnIdade = (Button)findViewById(R.id.edtIdade);
        edtDetalhes = (EditText)findViewById(R.id.edtDetalhe);
        btnTipoAnimal = (Button)findViewById(R.id.btnTipoAnimal);

        imagem = (ImageView) findViewById(R.id.btnimage);
        imageButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Toast.makeText(CadastroPerdido.this, "Adicionar Imagem do pet", Toast.LENGTH_SHORT).show();
                Intent intent  =  new Intent(Intent.ACTION_PICK,
                        android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
                startActivityForResult(intent, GALERIA);
            }
        }); // END imageButton.setOnClick

        btnTipoAnimal.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(final View v)
            {
                AlertDialog.Builder mBuilder = new AlertDialog.Builder(CadastroPerdido.this);
                final View mView = getLayoutInflater().inflate(R.layout.dialog_tipoanimal, null);
                final RadioButton btrDog = (RadioButton) mView.findViewById(R.id.btrDog);
                final RadioButton btrCat = (RadioButton) mView.findViewById(R.id.btrCat);
                final RadioButton btrBird = (RadioButton) mView.findViewById(R.id.btrBird);
                final RadioButton btrCoelho = (RadioButton) mView.findViewById(R.id.btrCoelho);
                final RadioButton btrOutros = (RadioButton) mView.findViewById(R.id.btrOutros);

                mBuilder.setView(mView)
                        .setTitle("Tipo de animal")
                        .setNegativeButton("Cancelar", null)
                        .setPositiveButton("Ok", new DialogInterface.OnClickListener()
                        {
                            @Override
                            public void onClick(DialogInterface dialog, int which)
                            {

                                if(btrDog.isChecked())
                                {
//                                    Toast.makeText(CadastroPerdido.this, "Cachorro",
//                                            Toast.LENGTH_SHORT).show();
                                    tipo_animal = "Cachorro";
                                }
                                if(btrCat.isChecked())
                                {
//                                    Toast.makeText(CadastroPerdido.this, "Gato",
//                                            Toast.LENGTH_SHORT).show();
                                    tipo_animal = "Gato";
                                }
                                if(btrBird.isChecked())
                                {
//                                    Toast.makeText(CadastroPerdido.this, "Passaro",
//                                            Toast.LENGTH_SHORT).show();
                                   tipo_animal = "Passaro";
                                }
                                if(btrCoelho.isChecked())
                                {
//                                    Toast.makeText(CadastroPerdido.this, "Coelho",
//                                            Toast.LENGTH_SHORT).show();
                                    tipo_animal = "Coelho";
                                }
                                if(btrOutros.isChecked())
                                {

                                    tipo_animal = "Outros";
                                }

//                                Toast.makeText(CadastroPerdido.this, tipo_animal,
//                                        Toast.LENGTH_SHORT).show();

                                AlertDialog.Builder mBuilder = new AlertDialog.Builder(CadastroPerdido.this);
                                final View mViewR = getLayoutInflater().inflate(R.layout.dialog_raca, null);
                                final RadioButton Raca1 = (RadioButton)mViewR.findViewById(R.id.ra1);
                                final RadioButton Raca2 = (RadioButton)mViewR.findViewById(R.id.ra2);
                                final RadioButton Raca3 = (RadioButton)mViewR.findViewById(R.id.ra3);
                                final RadioButton Raca4 = (RadioButton)mViewR.findViewById(R.id.ra4);
                                mBuilder.setView(mViewR)
                                        .setTitle("Raça do animal")
                                        .setNegativeButton("Cancelar", null)
                                        .setPositiveButton("Ok", new DialogInterface.OnClickListener()
                                        {
                                            @Override
                                            public void onClick(DialogInterface dialog, int which)
                                            {

                                                if(Raca1.isChecked())
                                                {
                                                    raca = "Raça1";
                                                }
                                                if(Raca2.isChecked())
                                                {
                                                    raca = "Raça2";
                                                }
                                                if(Raca3.isChecked())
                                                {
                                                    raca = "Raça3";
                                                }
                                                if(Raca4.isChecked())
                                                {
                                                    raca = "Raça4";
                                                }

                                                btnTipoAnimal.setText(
                                                        String.format("%s - %s", tipo_animal, raca));
                                            }
                                        });
                                AlertDialog dialogR = mBuilder.create();
                                dialogR.show();

                            }
                        });

                AlertDialog dialog = mBuilder.create();
                dialog.show();
            }
        });// END btnTipoAnimal.setOnClick

        btnIdade.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                AlertDialog.Builder mBuilder = new AlertDialog.Builder(CadastroPerdido.this);
                final View mView = getLayoutInflater().inflate(R.layout.dialog_idade, null);
                final RadioButton btrFil = (RadioButton)mView.findViewById(R.id.btrFil);
                final RadioButton btrAdu = (RadioButton)mView.findViewById(R.id.btrAdu);
                final RadioButton btrIdo = (RadioButton)mView.findViewById(R.id.btrIdo);

                mBuilder.setView(mView)
                        .setTitle("Tipo de animal")
                        .setNegativeButton("Cancelar", null)
                        .setPositiveButton("OK", new DialogInterface.OnClickListener()
                        {
                            @Override
                            public void onClick(DialogInterface dialog, int which)
                            {

                                if(btrFil.isChecked())
                                {
                                    idade = "Filhote";
                                }
                                if(btrAdu.isChecked())
                                {
                                    idade = "Adulto";
                                }
                                if(btrIdo.isChecked())
                                {
                                    idade = "Idoso";
                                }

                                btnIdade.setText(idade);
                            }
                        });

                AlertDialog alertDialog = mBuilder.create();
                alertDialog.show();
            }
        });// END btnIdade.setOnClick

        btnMostreOnde.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Toast.makeText(CadastroPerdido.this, "MOSTRE ONDE PERDEU", Toast.LENGTH_LONG)
                        .show();
                Intent it = new Intent(CadastroPerdido.this, InformeEndereco.class);
                startActivity(it);
            }
        });// END btnMostreOnde.setOnClick

        criarConexao();
    }

    private void confirmar()
    {
        perdido = new Perdidos();

        if(!validaCampos())
        {
          perdidosRepositorio.inserir(perdido);
          finish();
        }
    }

    public boolean validaCampos() // Valida os campos de descriçao
    {
        InformeEndereco endereco = new InformeEndereco();
        boolean res = false;

        String nome = edtNome.getText().toString();
        String corPelo = edtCorPelo.getText().toString();
        String infoA = edtDetalhes.getText().toString();

        perdido.nome    = nome;
        perdido.idade   = idade;
        perdido.tipo    = tipo_animal;
        perdido.cor     = corPelo;
        perdido.raca    = raca;
        perdido.infoA   = infoA;

        if(res = isCampoVazio(nome))
        {
            edtNome.requestFocus();
        }else
            if(res = isCampoVazio(idade))
        {
            btnIdade.requestFocus();
        }else
            if(res = isCampoVazio(corPelo))
            {
                edtCorPelo.requestFocus();
            }else
                if(res = isCampoVazio(tipo_animal))
                {
                    btnTipoAnimal.requestFocus();
                }

        if(res)
        {
            AlertDialog.Builder dlg = new AlertDialog.Builder(CadastroPerdido.this);
            dlg.setTitle(R.string.dlg_erro);
            dlg.setMessage(R.string.message_dlg_invalid);
            dlg.setNeutralButton(R.string.action_ok,null); //Fecha a tela de aviso
            dlg.show();
        }

        return res;
    }

    private boolean isCampoVazio(String valor) // verifica se tem campos em branco
    {
        boolean result = ( TextUtils.isEmpty(valor) || valor.trim().isEmpty() ); //Verifica se nao existe nenhum caracter
                                                        // Retira todos os espaços
        return result;
    }

    private void criarConexao()
    {
        try
        {
            dados = new Dados(this);

            conexao = dados.getWritableDatabase();

            Snackbar.make(layoutCadPer, "Conexão criada com sucesso!", Snackbar.LENGTH_SHORT)
                    .show();

            perdidosRepositorio = new PerdidosRepositorio(conexao);

        }catch(SQLException ex)
        {
            AlertDialog.Builder dlg = new AlertDialog.Builder(this);
            dlg
                    .setTitle("ERRO!")
                    .setMessage(ex.getMessage())
                    .setNeutralButton("OK", null)
                    .show();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        switch(id)
        {
            case R.id.action_Ok:
                confirmar();
                //Toast.makeText(this, "Botão Ok selecionado", Toast.LENGTH_SHORT).show();
                break;

            case android.R.id.home:
                //Toast.makeText(this, "Botão Cancelar selecionado", Toast.LENGTH_SHORT).show();
                finish();
                break;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) // Adicionar imagens
    {
        super.onActivityResult(requestCode, resultCode, data);
        if  (resultCode==  RESULT_OK  &&  requestCode == GALERIA)
        {
            Uri selectedImage = data.getData();
            String[]  filePath = {MediaStore.Images.Media.DATA};

            Cursor c = getContentResolver().query(selectedImage,filePath,  null,  null,  null);
            c.moveToFirst();

            int columnIndex = c.getColumnIndex(filePath[0]);
            String  picturePath = c.getString(columnIndex);
            c.close();

            Bitmap thumbnail = (BitmapFactory.decodeFile(picturePath));
            imagem.setImageBitmap(thumbnail);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           @NonNull String[] permissions, @NonNull int[] grantResults)
    {
        if(requestCode == PERMISSAO_REQUEST)
        {
            if(grantResults.length > 0
                    && grantResults[0] == PackageManager.PERMISSION_GRANTED)
            {
                // A permissão foi concedida. Pode continuar
            }else
            {
                //A permissão foi negada. Precisa ver o que deve ser desabilitado
            }

            return;
        }
    }


}
