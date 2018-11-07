package com.example.hugo.cademeutoto;

import android.content.Intent;
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
import android.widget.Toast;

public class CadastroPerdido extends AppCompatActivity
{
    private ImageButton imageButton;    // Adiciona a imagem do animal
    private Button btnMostreOnde;       // Mostre onde perdeu o Pet

    private EditText edtNome;
    private EditText edtIdade;
    private EditText edtCorPelo;
    private EditText edtDetalhes;
    private EditText edtTipoAnimal;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cadastro_perdido);

        imageButton = (ImageButton)findViewById(R.id.btnimage);     // Adiciona a imagem do animal
        btnMostreOnde = (Button)findViewById(R.id.btnMostreOnde);  // Mostre onde perdeu o Pet

        edtNome = (EditText)findViewById(R.id.edtNome);
        edtCorPelo = (EditText)findViewById(R.id.edtCorPelo);
        edtIdade = (EditText)findViewById(R.id.edtIdade);
        edtDetalhes = (EditText)findViewById(R.id.edtDetalhe);
        edtTipoAnimal = (EditText)findViewById(R.id.edtTipoAnimal);

        imageButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Toast.makeText(CadastroPerdido.this, "Adicionar Imagem", Toast.LENGTH_SHORT).show();
            }
        }); // end imageButton.setOnClick

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
        });
    }

    private boolean validaCampos() // Valida os campos de descriçao
    {
        boolean res = false;

        String nome = edtNome.getText().toString();
        String idade = edtIdade.getText().toString();
        String corPelo = edtCorPelo.getText().toString();
        String tipo_animal = edtTipoAnimal.getText().toString();
        String detalhe = edtDetalhes.getText().toString();

        if(res = isCampoVazio(nome))
        {
            edtNome.requestFocus();
        }else
            if(res = isCampoVazio(idade))
        {
            edtIdade.requestFocus();
        }else
            if(res = isCampoVazio(corPelo))
            {
                edtCorPelo.requestFocus();
            }else
                if(res = isCampoVazio(tipo_animal))
                {
                    edtTipoAnimal.requestFocus();
                }else
                    if(res = isCampoVazio(detalhe))
                    {
                        edtDetalhes.requestFocus();
                    }
        if(res)
        {
            AlertDialog.Builder dlg = new AlertDialog.Builder(this);
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
                validaCampos();
                //Toast.makeText(this, "Botão Ok selecionado", Toast.LENGTH_SHORT).show();
                break;

            case R.id.action_cancela:
                Toast.makeText(this, "Botão Cancelar selecionado", Toast.LENGTH_SHORT).show();
                finish();
                break;
        }

        return super.onOptionsItemSelected(item);
    }
}
