#include <iostream>
#include <cstdlib> 
using namespace std;

//1
void SelectionMethod(int B[], int count){
  for (int i = 0; i < count - 1; ++i)
  {
		int max = i;
		for (int k = i + 1; k < count; ++k)
		{
			if (B[k] > B[max])
				max = k;
		}
		swap(B[i], B[max]);
	}

  cout << "Сортировка методом выбора: " << "\n";
  for(int i = 0; i < count; i++){
    cout << B[i] << "\t";
  }
}

//2
void InsertSort(int B[], int count){
    int min = 0, j = 0;
    for (int i = 1; i < count; i++)
    {
        min = B[i];
        j = i - 1;
        while (j >= 0 && B[j] > min)
        {
            B[j + 1] = B[j];
            j--;
        }
        B[j + 1] = min;
    }

    cout << "Сортировка методом вставки: " << "\n";
    for(int i = 0; i < count; i++){
      cout << B[i] << "\t";
    }
}

int main() {
  int N;
  cout << "Введите размерность массива: " << "\n";
  cin >> N;
  int A[N];
  
  cout << "Начальный массив: " << "\n";
  for(int i = 0; i < N; i++){
    A[i] = 5 - rand() % 15;
    cout << A[i] << "\t";
  }
  
  int count = 0;
  for (int i = 0, k = 0; i < N ; i++){
    if(A[i] < 0){
      count++;
    }
  }

  int B[count];
  for (int i = 0, k = 0; i < N ; i++){
    if(A[i] < 0){
      B[k] = A[i];
      k++;
    }
  }

  cout << "\n";
  cout << "Массив отрицательных чисел: " << "\n";
  for(int i = 0; i < count; i++){
    cout << B[i] << "\t";
  }
  cout << "\n";

  SelectionMethod(B, count);
  cout << "\n";
  InsertSort(B, count);
}
