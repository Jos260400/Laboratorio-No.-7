/*----------
* ----------
* Universidad del Valle
* Programación de Microprocesadores
* Semestre 4, 2018
* Fernando José Garavito Ovando 18071
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// Recorrido

_global_
void prod(int n, float *x, float *y, float*z)
{
  int i = blockIdx.x*blockDim.x + threadIdx.x;
  if (i < n) z[i] = x[i] * y[i];
}

int main(void)
{
  int N = 1;
  srand (time(NULL));
  float *a, *b, *c, *d_a, *d_b, *d_c;
  a = (float*)malloc(N*sizeof(float));
  b = (float*)malloc(N*sizeof(float));
  c = (float*)malloc(N*sizeof(float));

// Asignar memoria de device
  cudaMalloc(&d_a, N*sizeof(float)); 
  cudaMalloc(&d_b, N*sizeof(float));
  cudaMalloc(&d_c, N*sizeof(float));

  for (int i = 0; i < N; i++) {
    a[i] = rand() % 10;
    b[i] = rand() % 10;
	c[i] = 0.0f;
  }
// Copiar datos de host a device
  cudaMemcpy(d_a, a, N*sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, b, N*sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_c, c, N*sizeof(float), cudaMemcpyHostToDevice);
