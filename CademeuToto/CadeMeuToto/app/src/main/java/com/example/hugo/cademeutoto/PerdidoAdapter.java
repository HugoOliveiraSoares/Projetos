package com.example.hugo.cademeutoto;

import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.hugo.cademeutoto.dominio.entidades.Perdidos;

import java.util.List;

public class PerdidoAdapter extends RecyclerView.Adapter<PerdidoAdapter.ViewHolderPerdido>
{

    private List<Perdidos> dados;

    public PerdidoAdapter(List<Perdidos> dados)
    {
        this.dados = dados;
    }

    @Override
    public PerdidoAdapter.ViewHolderPerdido onCreateViewHolder(@NonNull ViewGroup parent, int i)
    {
        LayoutInflater layoutInflater = LayoutInflater.from(parent.getContext());

        View view = layoutInflater.inflate(R.layout.linha_perdido, parent, false);

        ViewHolderPerdido holderPerdido = new ViewHolderPerdido((view));

        return holderPerdido;
    }

    @Override
    public void onBindViewHolder(@NonNull PerdidoAdapter.ViewHolderPerdido holder, int position)
    {
        if ( (dados != null) && (dados.size() > 0) )
        {

            Perdidos perdido = dados.get(position);

            holder.txtnome.setText(perdido.nome);
            holder.txtraca.setText(perdido.raca);
            holder.txtendereco.setText(perdido.endereco);
        }

    }

    @Override
    public int getItemCount() {
        return dados.size();
    }

    public class ViewHolderPerdido extends RecyclerView.ViewHolder
    {

        public TextView txtnome;
        public TextView txtraca;
        public TextView txtendereco;
        public ImageView imagePet;

        public ViewHolderPerdido(@NonNull View itemView)
        {
            super(itemView);

            txtnome = (TextView) itemView.findViewById(R.id.txtnome);
            txtraca = (TextView) itemView.findViewById(R.id.txtraca);
            txtendereco = (TextView) itemView.findViewById(R.id.txtendereco);
            imagePet = (ImageView) itemView.findViewById(R.id.imagePet);
        }
    }
}
