#ifndef _RAND_H_
#define _RAND_H_

/* Period parameters */  
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */

const double T[] = { 12.706, 4.303, 3.182, 2.776, 2.571, 2.447, 2.365, 2.308, 2.262, 
                     2.228, 2.201, 2.179, 2.160, 2.145, 2.131, 2.120, 2.110, 2.101, 
                     2.093, 2.086, 2.080, 2.074, 2.069, 2.064, 2.060, 2.056, 2.052, 
                     2.048, 2.045, 2.042, 2.021, 2.000, 1.980, 1.960 };

/* initializes mt[N] with a seed */
void init_genrand(unsigned long s);

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */
void init_by_array(unsigned long init_key[], int key_length);

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void);

/* generates a random number on [0,0x7fffffff]-interval */
long genrand_int31(void);

/* generates a random number on [0,1]-real-interval */
double genrand_real1(void);

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void);

/* generates a random number on (0,1)-real-interval */
double genrand_real3(void);

/* generates a random number on [0,1) with 53-bit resolution*/
double genrand_res53(void);

/*----------------------------------------------------------*/
/* valueOfT     renvoie la valeur du tableau t en fn de n   */
/*                                                          */
/* En entrée:   n le nombre d'expériences                   */
/*                                                          */
/* En sortie:   la valeur de t correspondant                */
/*----------------------------------------------------------*/
double valueOfT(int n);

/*----------------------------------------------------------*/
/* estimateVariance  estimer la variance pour une loi de    */
/*                      Student                             */
/*                                                          */
/* En entrée:   tmoy le tableau des résultats des tirages   */
/*              moy la moyenne des tirages                  */
/*              n le nombre de tirages                      */
/*                                                          */
/* En sortie:   la valeur estimée de la variance            */
/*----------------------------------------------------------*/
double estimateVariance(double tmoy[], double moy, int n);

/*----------------------------------------------------------*/
/* estimateRadius estimer le rayon de l'intervalle de       */
/*                  confiance                               */
/*                                                          */
/* En entrée:   tmoy le tableau des résultats des tirages   */
/*              moy la moyenne des tirages                  */
/*              n le nombre de tirages                      */
/*                                                          */
/* En sortie:   la valeur estimée du rayon de l'intervalle  */
/*                  confiance                               */
/*----------------------------------------------------------*/
double estimateRadius(double tmoy[], double moy, int n);

#endif