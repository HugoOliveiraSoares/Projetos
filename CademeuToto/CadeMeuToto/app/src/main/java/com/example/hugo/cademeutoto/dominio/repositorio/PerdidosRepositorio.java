package com.example.hugo.cademeutoto.dominio.repositorio;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import com.example.hugo.cademeutoto.dominio.entidades.Perdidos;

import java.util.ArrayList;
import java.util.List;

public class PerdidosRepositorio // Operações no banco de dados de animais pedidos
{

    private SQLiteDatabase conexao;

    public PerdidosRepositorio(SQLiteDatabase conexao)
    {
        this.conexao = conexao;
    }

    public void inserir(Perdidos perdidos)
    {
        ContentValues contentValues = new ContentValues();
        contentValues.put("NOME",  perdidos.nome);
        contentValues.put("TIPOANIMAL",  perdidos.tipo);
        contentValues.put("RACA",  perdidos.raca);
        contentValues.put("IDADE", perdidos.idade);
        contentValues.put("COR",   perdidos.cor);
        contentValues.put("INFO",  perdidos.infoA);
//        contentValues.put("ENDERECO", perdidos.endereco);

        conexao.insertOrThrow("CLIENTE", null, contentValues);

    }

    public void excluir(int codigo)
    {

        String[] parametros = new String[1];
        parametros[0] = String.valueOf(codigo);

        conexao.delete("CLIENTE","CODIGO = ? ", parametros);
    }

    public void alterar(Perdidos perdidos)
    {
        ContentValues contentValues = new ContentValues();
        contentValues.put("NOME",  perdidos.nome);
        contentValues.put("TIPOANIMAL",  perdidos.tipo);
        contentValues.put("RACA",  perdidos.raca);
        contentValues.put("IDADE", perdidos.idade);
        contentValues.put("COR",   perdidos.cor);
        contentValues.put("INFO",  perdidos.infoA);
        contentValues.put("ENDERECO", perdidos.endereco);

        String[] parametros = new String[1];
        parametros[0] = String.valueOf(perdidos.codigo);

        conexao.update("CLIENTE", contentValues, "CODIGO = ? ", parametros);

    }

    public List<Perdidos> buscarTodos()
    {
        List<Perdidos> clientes = new ArrayList<Perdidos>();

        StringBuilder sql = new StringBuilder();
        sql.append(" SELECT CODIGO, NOME, TIPOANIMAL, RACA, IDADE, COR, INFO, ENDERECO");
        sql.append("  FROM CLIENTE");

        Cursor resultado = conexao.rawQuery(sql.toString(), null);

        if(resultado.getCount() > 0)
        {
            resultado.moveToFirst();

            do
            {
                Perdidos perdidos = new Perdidos();

                perdidos.codigo = resultado.getInt(resultado.getColumnIndexOrThrow("CODIGO") );
                perdidos.nome = resultado.getString(resultado.getColumnIndexOrThrow("NOME") );
                perdidos.tipo = resultado.getString(resultado.getColumnIndexOrThrow("TIPOANIMAL") );
                perdidos.raca = resultado.getString(resultado.getColumnIndexOrThrow("RACA") );
                perdidos.idade = resultado.getString(resultado.getColumnIndexOrThrow("IDADE") );
                perdidos.cor = resultado.getString(resultado.getColumnIndexOrThrow("COR") );
                perdidos.infoA = resultado.getString(resultado.getColumnIndexOrThrow("INFO") );
                perdidos.endereco = resultado.getString(resultado.getColumnIndexOrThrow("ENDERECO") );

                clientes.add(perdidos);

            }while(resultado.moveToNext());

        }
        return clientes;
    }

    public Perdidos buscarPerdido(int codigo)
    {
        Perdidos perdidos = new Perdidos();

        StringBuilder sql = new StringBuilder();
        sql.append(" SELECT CODIGO, NOME, TIPOANIMAL, RACA, IDADE, COR, INFO, ENDERECO");
        sql.append("  FROM CLIENTE");
        sql.append(" WHERE CODIGO = ? ");

        String[] parametros = new String[1];
        parametros[0] = String.valueOf(codigo);

        Cursor resultado = conexao.rawQuery(sql.toString(), parametros);

        if(resultado.getCount() > 0)
        {
            resultado.moveToFirst();

            perdidos.codigo = resultado.getInt(resultado.getColumnIndexOrThrow("CODIGO"));
            perdidos.nome = resultado.getString(resultado.getColumnIndexOrThrow("NOME"));
            perdidos.tipo = resultado.getString(resultado.getColumnIndexOrThrow("TIPOANIMAL") );
            perdidos.raca = resultado.getString(resultado.getColumnIndexOrThrow("RACA") );
            perdidos.idade = resultado.getString(resultado.getColumnIndexOrThrow("IDADE") );
            perdidos.cor = resultado.getString(resultado.getColumnIndexOrThrow("COR") );
            perdidos.infoA = resultado.getString(resultado.getColumnIndexOrThrow("INFO") );
            perdidos.endereco = resultado.getString(resultado.getColumnIndexOrThrow("ENDERECO") );


            return perdidos;
        }

        return null;
    }
}
