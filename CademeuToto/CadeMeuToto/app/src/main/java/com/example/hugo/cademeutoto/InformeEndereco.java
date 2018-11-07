package com.example.hugo.cademeutoto;

import android.content.Context;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

public class InformeEndereco extends FragmentActivity implements OnMapReadyCallback,
        GoogleMap.OnMapClickListener, LocationListener
{

    private GoogleMap mMap; // Mapa da Google
    private LocationManager locationManager;

    private static final String TAG = "InformeEndereco";

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.act_informe_endereco);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);

    }

    @Override
    public void onResume()
    {
        super.onResume();
        // Ativa o GPS
        locationManager = (LocationManager)this.getSystemService(Context.LOCATION_SERVICE);
        locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0,0, this);

    }

    @Override
    public void onPause()
    {
        super.onPause();
        locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);
        locationManager.removeUpdates(this);
    }


    /**
     * Manipulates the map once available.
     * This callback is triggered when the map is ready to be used.
     * This is where we can add markers or lines, add listeners or move the camera. In this case,
     * we just add a marker near Sydney, Australia.
     * If Google Play services is not installed on the device, the user will be prompted to install
     * it inside the SupportMapFragment. This method will only be triggered once the user has
     * installed Google Play services and returned to the app.
     */
    @Override
    public void onMapReady(GoogleMap googleMap)
    {

        try {
            mMap = googleMap;

            locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);

            Criteria criteria = new Criteria();
            String provider = locationManager.getBestProvider(criteria, true);

            Toast.makeText(this, "Provider: " + provider, Toast.LENGTH_LONG)
                    .show();

            mMap.setOnMapClickListener(this);
            mMap.getUiSettings().setZoomControlsEnabled(true);

            mMap.setMyLocationEnabled(true);


        }catch(SecurityException ex)
        {
            Log.e(TAG, "ERRO", ex);
        }

        // Add a marker in Sydney and move the camera
        LatLng sydney = new LatLng(-31,141);
        MarkerOptions marker = new MarkerOptions();

        marker.position(sydney);
        marker.title("marcador em Sydney");
        mMap.addMarker(marker);     //mMap.addMarker(new MarkerOptions().position(sydney).title("Marker in Sydney"));
        mMap.moveCamera(CameraUpdateFactory.newLatLng(sydney));

    }

    @Override
    public void onMapClick(LatLng latLng)
    {
        Toast.makeText(this, "Cordenada" + latLng.toString(), Toast.LENGTH_SHORT)
                .show();

        MarkerOptions marker = new MarkerOptions();
        marker.position(latLng);
        marker.title("Perdi aqui");
        mMap.addMarker(marker);

        mMap.moveCamera(CameraUpdateFactory.newLatLng(latLng));
    }

    @Override
    public void onLocationChanged(Location location)
    {
        Toast.makeText(this, "Posição alterada", Toast.LENGTH_SHORT).show();

        LatLng mylocation = new LatLng(location.getLatitude(), location.getLongitude());
       //MarkerOptions marker = new MarkerOptions();

        //marker.position(mylocation);
        //marker.title("Nova localização");
        //mMap.addMarker(marker);

        mMap.moveCamera(CameraUpdateFactory.newLatLng(mylocation));
    }

    @Override
    public void onStatusChanged(String provider, int status, Bundle extras)
    {
        Toast.makeText(this, "Status do provider foi alterado", Toast.LENGTH_SHORT)
                .show();
    }

    @Override
    public void onProviderEnabled(String provider)
    {
        Toast.makeText(this, "Provider Habilitado", Toast.LENGTH_SHORT)
                .show();
    }

    @Override
    public void onProviderDisabled(String provider)
    {
        Toast.makeText(this, "Provider disabilitado", Toast.LENGTH_SHORT)
                .show();
    }
}
