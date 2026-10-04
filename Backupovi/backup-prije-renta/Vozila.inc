#pragma tabsize 0
#if defined _vozila_included
    #endinput
#endif
#define _vozila_included

#include <a_samp>

// Deklaracija za Hitnu
new V_Hitna[6];

// Varijable za brzu i jednostavnu proveru opsega vozila
new PrvoHitnoVozilo, ZadnjeHitnoVozilo;
new PrvoTaxiVozilo, ZadnjeTaxiVozilo;
new PrvoParkingVozilo, ZadnjeParkingVozilo;
new PrvoPostarskoVozilo, ZadnjePostarskoVozilo; // Nova linija za poštara

stock UcitajVozilaServera()
{
    new v;
    // Motori (Faggio 462)
    v = CreateVehicle(462, 1560.6187, -2308.7488, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(462, 1560.4720, -2312.0710, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(462, 1560.2976, -2315.4719, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(462, 1560.3861, -2318.7346, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(462, 1560.2943, -2322.0547, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(462, 1560.3639, -2325.2173, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(462, 1560.4131, -2328.5439, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(462, 1560.6046, -2331.8169, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(462, 1560.8038, -2334.8892, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(462, 1560.7866, -2338.3750, 13.0378, 90.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 

    // Auta (Glendale 445)
    v = CreateVehicle(445, 1556.3898, -2360.9287, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(445, 1552.6921, -2361.0425, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(445, 1549.3516, -2361.0688, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(445, 1546.1702, -2361.0703, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(445, 1542.8512, -2361.1343, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(445, 1539.6879, -2361.0964, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(445, 1536.2465, -2361.0317, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(445, 1533.1462, -2361.0618, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(445, 1529.9263, -2361.0295, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(445, 1526.4655, -2361.0952, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 

    // Auta (Premier 426)
    v = CreateVehicle(426, 1521.7623, -2360.9543, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(426, 1518.5216, -2360.8992, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(426, 1515.4224, -2360.9614, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(426, 1512.0427, -2360.9890, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(426, 1508.7010, -2360.9548, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(426, 1505.4595, -2360.8796, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(426, 1502.2593, -2360.8660, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(426, 1498.9597, -2360.8718, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(426, 1495.7802, -2360.9150, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 
    v = CreateVehicle(426, 1492.3600, -2360.9626, 13.3392, 0.0000, 1, 1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0); 

    // Hitna pomoć
    V_Hitna[0] = CreateVehicle(416, 1180.1444, -1338.7891, 13.7694, -90.0000, -1, -1, 100); SetVehicleParamsEx(V_Hitna[0], 0, 0, 0, 0, 0, 0, 0);
    PrvoHitnoVozilo = V_Hitna[0]; // Prvo hitno
    
    V_Hitna[1] = CreateVehicle(416, 1179.2167, -1309.1299, 13.7894, -90.0000, -1, -1, 100); SetVehicleParamsEx(V_Hitna[1], 0, 0, 0, 0, 0, 0, 0);
    V_Hitna[2] = CreateVehicle(416, 1124.5428, -1328.2601, 13.2423, 0.0000, -1, -1, 100); SetVehicleParamsEx(V_Hitna[2], 0, 0, 0, 0, 0, 0, 0);
    V_Hitna[3] = CreateVehicle(416, 1110.7925, -1328.2585, 13.2423, 0.0000, -1, -1, 100); SetVehicleParamsEx(V_Hitna[3], 0, 0, 0, 0, 0, 0, 0);
    V_Hitna[4] = CreateVehicle(416, 1097.7271, -1328.4103, 13.2423, 0.0000, -1, -1, 100); SetVehicleParamsEx(V_Hitna[4], 0, 0, 0, 0, 0, 0, 0);
    V_Hitna[5] = CreateVehicle(487, 1161.7656, -1312.2687, 31.6459, -90.0000, -1, -1, 100); SetVehicleParamsEx(V_Hitna[5], 0, 0, 0, 0, 0, 0, 0);
    ZadnjeHitnoVozilo = V_Hitna[5]; // Zadnje hitno

    // Taxi Vozila 
    PrvoTaxiVozilo = CreateVehicle(420, 1803.0803, -1906.3279, 13.0382, 90.0000, -1, -1, 100); SetVehicleParamsEx(PrvoTaxiVozilo, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(420, 1803.0411, -1911.8705, 13.0382, 90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(420, 1803.1119, -1918.1582, 13.0382, 90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(420, 1803.0775, -1924.6205, 13.0382, 90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(438, 1797.1310, -1932.7091, 13.2375, 0.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(438, 1790.5300, -1932.7096, 13.2375, 0.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(438, 1783.9164, -1932.6670, 13.2375, 0.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(409, 1780.6748, -1886.9285, 13.0371, -90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(420, 1777.7870, -1923.8710, 13.0382, -90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(420, 1777.6869, -1917.2616, 13.0382, -90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(420, 1777.5679, -1911.2786, 13.0382, -90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(420, 1777.5475, -1904.0967, 13.0382, -90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    ZadnjeTaxiVozilo = CreateVehicle(409, 1790.3400, -1886.9554, 13.0371, -90.0000, -1, -1, 100); SetVehicleParamsEx(ZadnjeTaxiVozilo, 0, 0, 0, 0, 0, 0, 0); // Zadnje taxi

    // Parking Servis Vozila (Towtruck 525)
    PrvoParkingVozilo = CreateVehicle(525, 1066.9498, -890.4918, 42.9678, 90.0000, -1, -1, 100); SetVehicleParamsEx(PrvoParkingVozilo, 0, 0, 0, 0, 0, 0, 0); // Prvo parking servis
    v = CreateVehicle(525, 1066.8440, -896.8936, 42.9678, 90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(525, 1066.9548, -904.0431, 42.9678, 90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(525, 1066.4802, -910.6948, 42.9678, 90.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    ZadnjeParkingVozilo = CreateVehicle(525, 1066.5499, -917.3849, 42.9678, 90.0000, -1, -1, 100); SetVehicleParamsEx(ZadnjeParkingVozilo, 0, 0, 0, 0, 0, 0, 0); // Zadnje parking servis

    // --- POŠTINSKA VOZILA (Burrito i Wayfarer) ---
    PrvoPostarskoVozilo = CreateVehicle(482, 301.3521, -1491.3137, 24.4652, 236.0000, -1, -1, 100); SetVehicleParamsEx(PrvoPostarskoVozilo, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(482, 304.4572, -1486.7357, 24.4652, 236.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(482, 307.6148, -1481.9985, 24.4652, 236.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(482, 301.6356, -1504.8340, 24.4652, 236.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(482, 298.3276, -1509.4292, 24.4652, 236.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(482, 294.7141, -1513.7662, 24.4652, 236.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(482, 291.5283, -1518.0371, 24.4652, 236.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(482, 288.1089, -1522.5724, 24.4652, 236.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(586, 291.8129, -1544.9111, 24.0664, 53.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(586, 294.5834, -1540.5424, 24.0664, 53.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(586, 297.6788, -1535.8837, 24.0664, 53.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(586, 279.2047, -1536.2314, 24.0664, -127.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    v = CreateVehicle(586, 282.5196, -1532.0427, 24.0664, -127.0000, -1, -1, 100); SetVehicleParamsEx(v, 0, 0, 0, 0, 0, 0, 0);
    ZadnjePostarskoVozilo = CreateVehicle(586, 285.8920, -1527.8243, 24.0664, -127.0000, -1, -1, 100); SetVehicleParamsEx(ZadnjePostarskoVozilo, 0, 0, 0, 0, 0, 0, 0);
}

// Funkcije provere
stock IsTaxiVozilo(vehicleid)
{
    if(vehicleid >= PrvoTaxiVozilo && vehicleid <= ZadnjeTaxiVozilo) return 1;
    return 0;
}

stock IsHitnaVozilo(vehicleid)
{
    if(vehicleid >= PrvoHitnoVozilo && vehicleid <= ZadnjeHitnoVozilo) return 1;
    return 0;
}

stock IsParkingServisVozilo(vehicleid)
{
    if(vehicleid >= PrvoParkingVozilo && vehicleid <= ZadnjeParkingVozilo) return 1;
    return 0;
}

// Nova stock funkcija za proveru poštarskih vozila preko raspona
stock IsPostarVozilo(vehicleid)
{
    if(vehicleid >= PrvoPostarskoVozilo && vehicleid <= ZadnjePostarskoVozilo) return 1;
    return 0;
}

stock InitParkingServisVozila()
{
    for(new v = PrvoParkingVozilo; v <= ZadnjeParkingVozilo; v++)
    {
        SetVehicleNumberPlate(v, "PARKING");
        SetVehicleToRespawn(v);
    }
}