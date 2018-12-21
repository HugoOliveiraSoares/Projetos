package com.example.hugo.cademeutoto;

import android.content.Intent;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.constraint.ConstraintLayout;
import android.support.design.widget.CoordinatorLayout;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.graphics.drawable.AnimationUtilsCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.view.ActionMode;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.Toast;

import com.example.hugo.cademeutoto.database.Dados;
import com.example.hugo.cademeutoto.dominio.entidades.Perdidos;
import com.example.hugo.cademeutoto.dominio.repositorio.PerdidosRepositorio;

import java.util.List;

import static android.widget.Toast.*;

public class MainActivity extends AppCompatActivity
{
    FloatingActionButton fab;
    Button btn1, btn2;
    Animation fabOpen, fabClose, rotateFrente, rotateTras;
    boolean isOpen = false;
    private ConstraintLayout layoutMain;
    private RecyclerView lstdados;

    private SQLiteDatabase conexao;
    private Dados dados;
    private PerdidosRepositorio perdidosRepositorio;

    private PerdidoAdapter perdidoAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        layoutMain = (ConstraintLayout) findViewById(R.id.layoutMain);
        lstdados = (RecyclerView) findViewById(R.id.lstdados);

      //Recupera o id dos botoẽs
        fab =  (FloatingActionButton) findViewById(R.id.fab);
        btn1 = (Button) findViewById(R.id.btn1); // Perdi meu Pet
        btn2 = (Button) findViewById(R.id.btn2); // Achei um Pet

      //Carrega as animações
        fabOpen  =     AnimationUtils.loadAnimation(this, R.anim.fab_open);
        fabClose =     AnimationUtils.loadAnimation(this, R.anim.fab_close);
        rotateFrente = AnimationUtils.loadAnimation(this, R.anim.rotate_frente);
        rotateTras   = AnimationUtils.loadAnimation(this, R.anim.rotate_tras);

        fab.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                animateFab();
            }
        });

        btn1.setOnClickListener(new View.OnClickListener() //Perdi meu Pet
        {
            @Override
            public void onClick(View v)
            {
                animateFab();
                Intent it = new Intent(MainActivity.this, CadastroPerdido.class);
                //startActivity(it);
                startActivityForResult(it, 0);

            }
        });

        btn2.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                animateFab();
                Toast.makeText(MainActivity.this, "Floder clicked", Toast.LENGTH_SHORT).show();
            }
        });

        criarConexao();

        lstdados.setHasFixedSize(true);

        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(this);
        lstdados.setLayoutManager(linearLayoutManager);

        perdidosRepositorio = new PerdidosRepositorio(conexao);

        List<Perdidos> dados = perdidosRepositorio.buscarTodos();

        perdidoAdapter = new PerdidoAdapter(dados);

        lstdados.setAdapter(perdidoAdapter);

    }

    private void criarConexao()
    {
        try
        {
            dados = new Dados(this);

            conexao = dados.getWritableDatabase();

            Snackbar.make(layoutMain, "Conexão criada com sucesso!", Snackbar.LENGTH_SHORT)
                    .show();

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

    private void animateFab() // Execução da animação
    {
        if(isOpen)
        {
            fab.startAnimation(rotateFrente);
            btn1.startAnimation(fabClose);
            btn2.startAnimation(fabClose);
            btn1.setClickable(false);
            btn2.setClickable(false);
            isOpen = false;
        }else
        {
            fab.startAnimation(rotateTras);
            btn1.startAnimation(fabOpen);
            btn2.startAnimation(fabOpen);
            btn1.setClickable(true);
            btn2.setClickable(true);
            isOpen = true;
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data)
    {
        List<Perdidos> dados = perdidosRepositorio.buscarTodos();
        perdidoAdapter = new PerdidoAdapter(dados);
        lstdados.setAdapter(perdidoAdapter);

    }
}
