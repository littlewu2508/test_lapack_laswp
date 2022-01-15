#include "stdio.h"
#include "cblas.h"

void dlaswp_(int* n, double* A, int* lda, int* k1, int* k2, int* ipiv, int* inc);
int main()
{
	int lda = 100;
	int n = 192;
	int k1 = 20;
	int k2 = 100;
	int incx = -2;
	int ipiv[100*2]={60,70,0,0,0,32562,1936482630,1145831525,1717990722,1867280997,0,0,1702064961,1968403570,18,0,26,0,0,0,1,32562,178143120,0,1702256983,1852797542,1651469383,1884515425,10,-1519687063,10,1701594482,10,-1589484447,10,2105254508,10,-1338465963,10,1716482916,10,1951625829,10,1953394499,10,1818314405,10,1632019812,10,-1586270871,10,-1402637460,10,1801675088,10,1816223596,10,1920225396,10,1986090935,10,540684411,10,1699439980,10,-1372544703,10,1919899487,10,1919250511,10,1688928323,10,-1587057599,10,-1519885452,10,1702259058,10,1682518083,10,1886999661,10,1967307365,10,1869898597,10,1701079410,10,1967280964,10,1836404339,10,1934974894,10,1769108563,10,1634497901,10,1819632741,10,1818586738,10,1933650905,10,1634497891,10,878138975,10,1768838499,10,1700160867,10,1702064961,10,-1235395678,10,825795699,10,1702195796,10,23426412,10,1852142707,10,1851879544,10,1399155817,10,1784827749,10,1867279733,10,1398747211,10,1818586738,10,1467117428,10,1933685553,10,1920234350,10,1699767674,10,1919833519,10,1701080681,10,1839923315,10,1634030188,10,1802661719,10,1403662497,10,1449489513,10,1129074271,10,1702521171,10,765617522,10,1953264973,10,1917283186,10,1129729188,10,950087781,10,1667851365,10,1885425008,10,1867295845,10,1097756521,10,2019642797,10,1835363397,10,1281306689,10,1990552673,10,808755833,10,1769237621,10,1471438129,10,-1539792575,10,1968417078,10,1956938085};
#include "A.c"
	dlaswp_(&n, A, &lda, &k1, &k2, ipiv, &incx);
	printf("Hello World!\n");
	return 0;
}