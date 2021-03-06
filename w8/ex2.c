#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include "string.h"

int main(void)
{
  const unsigned long long mem = 15; // 15mb
  for (int t = 0; t < 10; t++)
  {
    void* x = malloc(mem * 1024ll*1024);
    memset(x, 0, mem * 1024ll*1024);
    sleep(1);
  }
}

/*
       free   active   specul inactive throttle    wired  prgable   faults     copy    0fill reactive   purged file-backed anonymous cmprssed cmprssor  dcomprs   comprs  pageins  pageout  swapins swapouts
   44941   321614      702   329641        0   846047    43824 7750116K  336725K 2646371K  186528K 83540180      208779    443178  2689621   553841  207115K  302817K 63491526   931102 31415984 33206605
   42386   324146      703   329625        0   846243    43644     7799      368     4024        0        0      208780    445694  2689595   553841       26        0        0        0        0        0
   39750   333912      703   332655        0   836039    53837     7043      346     3872        0        0      208780    458490  2689586   553841        9        0        0        0        0        0
   37250   335230      703   333915        0   836043    53861     7030      336     3885        0        0      208780    461068  2689580   553841        6        0        0        0        0        0
   34525   336516      709   335142        0   836047    53837     7013      326     3850        0        0      208786    463581  2689562   553841       18        0        0        0        0        0
   42239   327915      709   336177        0   836050    43666     7108      346     3938        0        0      208786    456015  2689555   553841        7        0        0        0        0        0
   39653   330564      715   336116        0   836056    43642     7210      336     4058        0        0      208792    458603  2689543   553841       12        0        0        0        0        0
   37093   333233      731   335961        0   836065    43696     8626      355     5131        0        0      208808    461117  2689514   553841       29        0        0        0        0        0
   34339   335904      731   335955        0   836065    43642     6693      317     3868        0        0      208808    463782  2689509   553841        5        0        0        0        0        0
   31644   338090      736   336616        0   836073    43642     7576      336     3899       24        0      208813    466629  2689199   553729      310        0        0        0        0        0
   28995   339365      736   338006        0   836042    43674     7067      344     3907        0        0      208813    469294  2689193   553729        6        0        0        0        0        0
   54620   322185      676   329567        0   836007    43674     4414      338     1242       93        0      208753    443675  2689180   553729       13        0        0        0        0        0
   55596   321523      682   329533        0   835936    43698     4848      351     1235        0        0      208759    442979  2689110   553729       70        0        0        0        0        0
   54787   322287      691   329506        0   836014    43675     4290      327     1272        0        3      208768    443716  2689106   553729        4        0        0        0        0        0
   54716   322287      691   329501        0   836008    43699     4229      328     1309        0        0      208768    443711  2689106   553729        0        0        0        0        0        0
   54660   322268      691   329501        0   836008    43675     4437      336     1270        0        0      208768    443692  2689093   553729       13        0        0        0        0        0
   55497   321625      691   329499        0   835936    43675     4774      348     1318        0        0      208768    443047  2689083   553713       10        0        0        0        0        0
   55039   321803      712   329491        0   835940    43675     5929      336     2665        0        0      208789    443217  2689010   553745       58        0        0        0       64        0
   55046   321834      712   329490        0   836002    43675     5021      335     1342        0        0      208789    443247  2688985   553745       25        0        0        0        0        0
   54784   322226      713   329482        0   836002    43675     5514      448     1408        0        0      208790    443631  2688851   553713      134        0        0        0        0        0
   54733   322197      713   329475        0   835992    43675     4414      341     1294        0        0      208790    443595  2688850   553713        1        0        0        0        0        0

swaps don't occur much since there's a lot of RAM in my computer so it doesn't require swapping


more swaps popped out when i made it 150MB each step:
    free   active   specul inactive throttle    wired  prgable   faults     copy    0fill reactive   purged file-backed anonymous cmprssed cmprssor  dcomprs   comprs  pageins  pageout  swapins swapouts
   24195   366915    28025   346112        0   781870    80034 7781573K  337504K 2668725K  187941K 85117527      236932    504120  2696475   549788  208694K  315922K 63901249   935545 31630652 33446598
    5111   379581      257   379323        0   782015    90013    43030      330    49982     4405        4      208436    550725  2698181   550512      142     1848        0      176        0        0
   23052   381765      505   380791        0   771737   100204    42946      336    39770    17873        2      208432    554629  2742774   538901       17    44610        0        1        0    18635
    4416   389740      504   388725        0   771748    99070    43803      445    39805     1404      844      208431    570538  2761497   541627       79    18802        0        0        0       64
    4094   389773      270   388959        0   770489    85092    42052      227    39605     3584        2      208197    570805  2799307   543336       15    37833        0        1        0      128
    3558   390157      463   388924        0   770445    81417    43135      342    39800      806        4      208390    571154  2837438   543328      123    38254      177        0        0        0
    4415   389582      452   388518        0   770355    77601    42733      330    39613      122        4      208378    570174  2876757   543600        8    39350        0        0        0        0
    4068   389603      199   389530        0   770382    57996    43783      443    39738        1     4817      208125    571207  2899033   543120      131    32625        0        1        0        0
    7753   386253      196   389277        0   770328    41362    43274      344    39794        2    15949      208122    567604  2924641   543076      110    26020        0        5        0        0
    3714   389808      197   389934        0   770276    16479    43000      336    39816        0    14691      208123    571816  2901663   542746       42     9214        0        0        0        0
    3788   390071       27   389390        0   770173    14431    15156      360    11579        0     2050      207954    571534  2909583   542746       43     7963        0        1        0        0
    3577   390502      263   389632        0   770100    14449    34889      336    31323       12        0      208192    572205  2938323   542737      266    29006      217        0       64        0
  240601   272354      286   271679        0   769199    14449     4222      329     1049        0        2      208197    336122  2790091   542737       97     1280        0        0        0        0
  239997   272841      291   271837        0   769207    14449     5258      343     1827        0        0      208202    336767  2789886   542732      160        0        0        0        0        0
  240213   272556      296   271902        0   769210    14449     4172      327     1092        0        1      208207    336547  2789855   542731       31        0        0        0        0        0
  240222   272563      296   271895        0   769210    14449     4476      344     1247        0        0      208207    336547  2789840   542731       11        0        0        0        0        0
  239624   272886      360   272004        0   769213    14503     4812      337     1549        0        0      208400    336850  2789795   542731       45        0      129        0        0        0
  239713   272814      361   272070        0   769210    14673     4439      335     1304        0        0      208401    336844  2789781   542731       14        0        0        0        0        0
  239752   272827      361   272029        0   769212    14673     4403      336     1257        0        0      208401    336816  2789773   542731        8        0        0        0        0        0
  239526   272906      361   271984        0   769214    14673     5920      337     2707        0        0      208401    336850  2789757   542795       16        0        0        0       64        0
  239514   273052      361   271970        0   769213    14673     4533      336     1339        0        0      208401    336982  2789718   542795       39        0        0        0        0        0


when i ran "top -i 1" on the proces (15MB every second) it failed to allocate 35k times (FAULTS)
Processes: 826 total, 4 running, 822 sleeping, 2233 threads                                                                                                                                        15:53:35
Load Avg: 2.25, 2.34, 2.60  CPU usage: 25.9% user, 16.27% sys, 58.62% idle  SharedLibs: 172M resident, 42M data, 13M linkedit. MemRegions: 179725 total, 1417M resident, 59M private, 612M shared.
PhysMem: 7849M used (3143M wired), 341M unused. VM: 3703G vsize, 1882M framework vsize, 31916824(0) swapins, 33749644(0) swapouts. Networks: packets: 86579563/98G in, 29395446/6736M out.
Disks: 34630509/485G read, 44380981/408G written.

PID    COMMAND      %CPU TIME     #TH   #WQ  #PORTS  MEM    PURG   CMPRS  PGRP  PPID  STATE    BOOSTS               %CPU_ME %CPU_OTHRS UID  FAULTS     COW     MSGSENT     MSGRECV     SYSBSD
21333  Terminal     60.9 08:38.84 11/1  4    373     223M+  0B-    15M-   21333 1     running  *1[24324]            0.02081 2.31622    501  14866075+  707     1840525+    462100+     3807322+
20703  top          19.2 00:01.82 1/1   0    25      9084K  0B     0B     20703 9396  running  *0[1]                0.00000 0.00000    0    9228+      90      542270+     271120+     28127+
284    WindowServer 18.9 20:28:41 12    6    4243    1083M  22M+   109M   284   1     sleeping *0[1]                2.26161 0.02068    88   114839450+ 507443  972433721+  457781791+  497264479+
0      kernel_task  9.1  16:30:35 263/4 0    0       486M+  0B     0B     0     0     running   0[0]                0.00000 0.00000    0    11178450   0       2573975301+ 2251410226+ 0
186    hidd         5.1  01:45:50 5     3    256     3900K  0B     1668K- 186   1     sleeping *0[1]                0.05957 0.00000    261  7813455+   168     35992486+   23366883+   215768717+
234    coreaudiod   2.3  05:14:47 14    3    537     9428K  0B     7188K  234   1     sleeping *0[1]                0.00000 0.09479    202  4629167+   280     349652215+  79052831+   386037841+
386    trustd       1.3  03:24:42 5     4    159     10M    72K    3424K  386   1     sleeping *0[7377735+]         0.00000 1.24569    501  1202768    204     43672188+   11320968+   148971531+
20702  ex2          0.7  00:00.09 1     0    10      135M+  0B     0B     20702 9396  sleeping *0[1]                0.00000 0.00000    501  34901+     90      45+         22+         107+
97896  routined     0.3  00:06.57 3     2    123+    12M+   0B     9492K- 97896 1     sleeping  0[177]              0.00000 0.00000    501  137473+    330     7754+       2129+       77251+
1      launchd      0.3  90:41.69 3     2    3168    23M    0B     11M    1     0     sleeping  0[0]                0.00000 0.21871    0    1245053    25784   156835844+  39708052+   157114217+


   */

