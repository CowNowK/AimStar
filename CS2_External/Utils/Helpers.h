#pragma once
#ifdef _DEBUG
#define JZ(x) if(x == 0) printf("[AIMSTAR] - %s address returned 0 on file %s at line %d \n",#x,__FILE__,__LINE__)
#else 
#define JZ(x) if(x == 0) return x;
#endif