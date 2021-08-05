program :- read(A), what(A), nl.

ruangan(ruang_makan).
ruangan(ruang_keluarga).
ruangan(dapur).
ruangan(kamar).
ruangan(toiler).
ruangan(teras).

lokasi(sofa, ruang_keluarga).
lokasi(meja, ruang_keluarga).
lokasi(meja, ruang_makan).
lokasi(pot, kamar).
lokasi(kasur, kamar).
lokasi(kulkas, dapur).
lokasi(kompor, dapur).
lokasi(tv, ruang_keluarga).
lokasi(kloset, toilet).
lokasi(lukisan, ruang_makan).
lokasi(lukisan, kamar).

:- program.