//Прототипы функций, используемых в данном задании :
//void VarArgs(int arg1, ...);
const int N = 5;
const int M = 10;

void Sort(char* pcFirst, int nNumber, int size,
void(*Swap)(void*, void*), int(*Compare)(void*, void*));
void SwapInt(void* p1, void* p2);
void SwapDouble(void* p1, void* p2);
void SwapChar(void* p1, void* p2);
int CmpInt(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);
int CmpChar(void* p1, void* p2);

const char* GetString1();
const char* GetString2();
const char* GetString3();
const char* GetString4();
const char* GetString5();

void PrintArray(int(*ar)[M], size_t N);
void PrintArray(int* pArr, size_t N, size_t M);

int DayOfYear(size_t day, size_t month, size_t year, int nDayTab[][12]);
void DayOfMonth(int day_of_year, int curr_year, int& result_day, int& result_month, int nDayTab[][12]);

void VarArgs(int arg1, ...);
void VarArgsMacro(int arg1, ...);

double Sum(double op1, double op2);
double Sub(double op1, double op2);
double Mul(double op1, double op2);
double Div(double op1, double op2);

void PrAr(int* ar, size_t N);
void PrAr(double* ar, size_t N);
