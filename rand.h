#ifndef _RAND_H_
#define _RAND_H_

/* Period parameters */  
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

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