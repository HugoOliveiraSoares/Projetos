package com.example.hugo.cademeutoto;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Build;
import android.provider.Settings;
import android.support.constraint.ConstraintLayout;
import android.support.design.widget.Snackbar;
import android.support.v4.app.ActivityCompat;
import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.util.Log;
import android.widget.Toast;

import com.google.android.gms.maps.CameraUpdate;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;

import java.util.ArrayList;

public class InformeEndereco extends FragmentActivity implements OnMapReadyCallback,
        GoogleMap.OnMapClickListener, LocationListener
{
    private GoogleMap mMap;
    private Marker currentLocationMaker;
    private LatLng currentLocationLatLong;

    private ConstraintLayout layoutMap;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.act_informe_endereco);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);

        layoutMap = (ConstraintLayout) findViewById(R.id.layoutMap);
        Snackbar.make(layoutMap, "Toque no local onde perdeu o animal", Snackbar.LENGTH_LONG)
                .show();

        startGettingLocations();
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
//        mMap = googleMap;
//
//        // Add a marker in Sydney and move the camera
//        LatLng sydney = new LatLng(-19.919431, -43.892274);
//        mMap.addMarker(new MarkerOptions().position(sydney).title("Marker in Sydney"));
////        mMap.moveCamera(CameraUpdateFactory.newLatLng(sydney));
//        CameraPosition cameraPosition = new CameraPosition.Builder().zoom(16).target(sydney).build();
//        CameraUpdate update = CameraUpdateFactory.newCameraPosition(cameraPosition);
//        mMap.animateCamera(update);try
        try{
            mMap = googleMap;

           LocationManager locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);

            Criteria criteria = new Criteria();
            /*String provider =*/ locationManager.getBestProvider(criteria, true);
//            Toast.makeText(this, "Provider: " + provider, Toast.LENGTH_LONG)
//                    .show();

            mMap.setOnMapClickListener(this);
            mMap.getUiSettings().setZoomControlsEnabled(true);
//           mMap.setMyLocationEnabled(true);

        }catch(SecurityException ex)
        {
            Log.e("MapReady", "ERRO", ex);
        }
        // Add a marker in Sydney and move the camera
//        LatLng sydney = new LatLng(-31,141);
//        MarkerOptions marker = new MarkerOptions();
//
//        marker.position(sydney);
//        marker.title("marcador em Sydney");
//        mMap.addMarker(marker);     //mMap.addMarker(new MarkerOptions().position(sydney).title("Marker in Sydney"));
//        CameraPosition cameraPosition = new CameraPosition.Builder().zoom(17).target(sydney).build();
//        CameraUpdate update = CameraUpdateFactory.newCameraPosition(cameraPosition);
//        mMap.animateCamera(update);
    }

    @Override
    public void onLocationChanged(Location location)
    {
        currentLocationLatLong = new LatLng(location.getLatitude(), location.getLongitude());
        addMarker(currentLocationLatLong, "Perdi o pet aqui");

        mMap.setOnInfoWindowClickListener(new GoogleMap.OnInfoWindowClickListener()
        {
            @Override
            public void onInfoWindowClick(Marker marker)
            {
                Log.i("InfoWindowClick", "1: Info Clicado");
                finish();
            }
        });
    }

    @Override
    public void onMapClick(LatLng latLng)
    {
        addMarker(latLng, "Perdi o pet aqui");

        mMap.setOnInfoWindowClickListener(new GoogleMap.OnInfoWindowClickListener()
        {
            @Override
            public void onInfoWindowClick(Marker marker)
            {
//                Toast.makeText(MapsActivity.this,"Info Click", Toast.LENGTH_SHORT)
//                        .show();
                Log.i("InfoWindowClick", "2: Info Clicado");
                finish();
            }
        });
    }

    @Override
    public void onStatusChanged(String provider, int status, Bundle extras)
    {
//        Toast.makeText(this, "Status do provider foi alterado", Toast.LENGTH_SHORT)
//                .show();
    }

    @Override
    public void onProviderEnabled(String provider)
    {
//        Toast.makeText(this, "Provider Habilitado", Toast.LENGTH_SHORT)
//                .show();
    }

    @Override
    public void onProviderDisabled(String provider)
    {
        Toast.makeText(this, "Provider desabilitado", Toast.LENGTH_SHORT)
                .show();
    }

    public void addMarker(LatLng latLng, String title) // Adiciona marcador
    {
        if(currentLocationMaker != null)
        {
            currentLocationMaker.remove();
        }

        MarkerOptions marker = new MarkerOptions();
        marker.position(latLng)
                .title(title)
                .draggable(true)
                .icon(BitmapDescriptorFactory.defaultMarker(BitmapDescriptorFactory.HUE_GREEN));

        currentLocationMaker = mMap.addMarker(marker);
        CameraPosition cameraPosition = new CameraPosition.Builder().zoom(17).target(latLng).build();
        CameraUpdate update = CameraUpdateFactory.newCameraPosition(cameraPosition);
        mMap.animateCamera(update);
    }

    private void startGettingLocations()
    {

        LocationManager lm = (LocationManager) getSystemService(Context.LOCATION_SERVICE);

        boolean isGPS = lm.isProviderEnabled(LocationManager.GPS_PROVIDER);
        boolean isNetwork = lm.isProviderEnabled(LocationManager.NETWORK_PROVIDER);
        boolean canGetLocation = true;
        int ALL_PERMISSIONS_RESULT = 101;
        long MIN_DISTANCE_CHANGE_FOR_UPDATES = 10;// Distance in meters
        long MIN_TIME_BW_UPDATES = 1000 * 10;// Time in milliseconds

        ArrayList<String> permissions = new ArrayList<>();
        ArrayList<String> permissionsToRequest;

        permissions.add(android.Manifest.permission.ACCESS_FINE_LOCATION);
        permissions.add(android.Manifest.permission.ACCESS_COARSE_LOCATION);
        permissionsToRequest = findUnAskedPermissions(permissions);

        //Check if GPS and Network are on, if not asks the user to turn on
        if (!isGPS && !isNetwork) {
            showSettingsAlert();
        } else {
            // check permissions

            // check permissions for later versions
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                if (permissionsToRequest.size() > 0) {
                    requestPermissions(permissionsToRequest.toArray(new String[permissionsToRequest.size()]),
                            ALL_PERMISSIONS_RESULT);
                    canGetLocation = false;
                }
            }
        }


        //Checks if FINE LOCATION and COARSE Location were granted
        if (ActivityCompat.checkSelfPermission(this,
                android.Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED &&
                ActivityCompat.checkSelfPermission(this, android.Manifest.permission.ACCESS_COARSE_LOCATION)
                        != PackageManager.PERMISSION_GRANTED) {

            Toast.makeText(this, "Permissão negada", Toast.LENGTH_SHORT).show();
            return;
        }

        //Starts requesting location updates
        if (canGetLocation)
        {
            if (isNetwork)
            {
                lm.requestLocationUpdates(
                        LocationManager.NETWORK_PROVIDER,
                        MIN_TIME_BW_UPDATES,
                        MIN_DISTANCE_CHANGE_FOR_UPDATES, this);

            } else if (isGPS)
            {
                // from Network Provider

                lm.requestLocationUpdates(
                        LocationManager.GPS_PROVIDER,
                        MIN_TIME_BW_UPDATES,
                        MIN_DISTANCE_CHANGE_FOR_UPDATES, this);

            }
        } else {
            Toast.makeText(this, "Não é possível obter a localização", Toast.LENGTH_SHORT).show();
        }
    }


    private ArrayList findUnAskedPermissions(ArrayList<String> wanted)
    {
        ArrayList result = new ArrayList();

        for (String perm : wanted)
        {
            if (!hasPermission(perm))
            {
                result.add(perm);
            }
        }

        return result;
    }

    private boolean hasPermission(String permission)
    {
        if (canAskPermission()) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                return (checkSelfPermission(permission) == PackageManager.PERMISSION_GRANTED);
            }
        }
        return true;
    }

    private boolean canAskPermission()
    {
        return (Build.VERSION.SDK_INT > Build.VERSION_CODES.LOLLIPOP_MR1);
    }

    public void showSettingsAlert()
    {
        AlertDialog.Builder alertDialog = new AlertDialog.Builder(this);
        alertDialog.setTitle("GPS desativado!");
        alertDialog.setMessage("Ativar GPS?");
        alertDialog.setPositiveButton("Sim", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int which) {
                Intent intent = new Intent(Settings.ACTION_LOCATION_SOURCE_SETTINGS);
                startActivity(intent);
            }
        });

        alertDialog.setNegativeButton("Não", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        });

        alertDialog.show();
    }

}