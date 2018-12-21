package com.example.hugo.cademeutoto.database;

public class ScripDLL
{
    public static String getCreateTableCliente()
    {
        StringBuilder sql = new StringBuilder();

        sql.append("CREATE TABLE IF NOT EXISTS CLIENTE ( ");
        sql.append("    CODIGO   INTEGER      PRIMARY KEY AUTOINCREMENT NOT NULL, ");
        sql.append("    NOME     VARCHAR(250) NOT NULL DEFAULT(''), ");
        sql.append("    TIPOANIMAL VARCHAR(255) NOT NULL DEFAULT(''), ");
        sql.append("    RACA    VARCHAR(200) NOT NULL DEFAULT(''), ");
        sql.append("    IDADE VARCHAR(200)  NOT NULL DEFAULT(''), ");
        sql.append("    COR VARCHAR(255)  NOT NULL DEFAULT(''), ");
        sql.append("    ENDERECO VARCHAR(250)  NOT NULL DEFAULT(''), ");
        sql.append("    INFO VARCHAR(255)  NOT NULL DEFAULT('') ) ");

        return sql.toString();
    }
}
