#include <iostream>
#include <fstream>

using namespace std;

void Skaitymas(int& n, double L[],int l_sk, double S[], int s_sk, double A[], int a_sk );
double Vidurkis(double Skaiciai[], int kiekis);

int main()
{
	double L[31], S[31], A[31];
	int n;
	int l_sk = 0, s_sk = 0, a_sk = 0;
	Skaitymas(n, L, l_sk, S, s_sk, A, a_sk);
	Vidurkis(S, s_sk);
}

void Skaitymas(int& n, double L[], int l_sk, double S[], int s_sk, double A[], int a_sk)
{
	char simbolis;
	double temp;

	ifstream in("orai_data.txt");

	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> simbolis >> temp;
		if (simbolis == 'L') {
			L[l_sk] = temp;
			l_sk++;
		}
		else
		{
			if (simbolis == 'S') {
				S[s_sk] = temp;
				s_sk++;
			}
			else
			{
				if (simbolis == 'A') {
					A[a_sk] = temp;
					a_sk++;
				}
			}
		}
	}
	in.close();
}

double Vidurkis(double Skaiciai[], int kiekis)
{
	double sum = 0;
	for (int i = 0; i < kiekis; i++)
	{
		sum += Skaiciai[i];
	}
	if (sum <= 0)
	{
		return 0;
	}
	else
	{
		return sum / kiekis;
	}
}