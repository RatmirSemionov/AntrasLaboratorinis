# PirmasLaboratorinis

Sistemos parametrai: Intel(R) Celeron(R) CPU 5205U @ 1.90GHz, RAM: 8.00GB, SSD: 225GB.

Testavimo vidurkiai su vector:
| Testavimas                    |      1000      |     10000     |     100000    |     1000000    |     10000000    |
|-------------------------------|:--------------:|:-------------:|:-------------:|:--------------:|:---------------:|
| Failo Nuskaitymas             |  0.00474288 s. | 0.07705792 s. |  0.8252412 s. |   7.056874 s.  |   74.33216 s.   |
| Sort() veiksmas               | 0.000142492 s. |  0.0195622 s. |  0.3513392 s. |   4.145426 s.  |   53.74884 s.   |
| Padalijimas į dvi kategorijas |  0.00250514 s. | 0.00430474 s. | 0.06608228 s. |  0.6064022 s.  |   7.690488 s.   |
| Rašymas į vargščiukų failą    |  0.00150928 s. |  0.0168969 s. |  0.152845 s.  |   1.611866 s.  |   20.86688 s.   |
| Rašymas į galvočių failą      |      0 s.      |  0.0112793 s. |  0.1410478 s. |   1.439764 s.  |   18.45458 s.   |
| Bendras Matavimas             |  0.0087573 s.  | 0.10953886 s. | 1.18521492 s. | 10.71491118 s. | 121.34410962 s. |
