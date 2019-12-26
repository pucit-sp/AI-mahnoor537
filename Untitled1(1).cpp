#include <iostream>
using namespace std;

static bool ex=false;
static int g=0;
void assign(int a[3][3], int b[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}
void print(int a[3][3],int bound)
{
	cout<<"depth:"<<g-bound<<'\n';
	for (int i = 0; i < 3; i++)
	{
		cout << " -------------\n";
		for (int j = 0; j < 3; j++)
		{
			cout << " | ";
			cout << a[i][j];
			if (j == 2)
				cout << " | \n";
		}
		if (i == 2)
			cout << " -------------\n";
	}
	cout<<"\n";
}
void swap(int &a, int &b)
{
	int temp; 
	temp= a;
	a = b;
	b = temp;
}
bool goal(int a[3][3])
{
	if (a[0][0] == 1 && a[0][1] == 2 && a[0][2] == 3 && a[1][2] == 4 && a[2][2] == 5 && a[2][1] == 6 && a[2][0] == 7 && a[1][0] == 8)
		{
		    cout<<"GGGGGGOOOOOOOAAAAALLLLLLL!!\n\n";
			return true;
		}
	else
		return false;

}
bool DLS(int a[3][3], int bound)
{
	bool ch=false;
	ch=goal(a);
	if (ch==true && bound>=0)
	{
		ex=true;
		//print(a,bound);
		return true;
	}
	if (ch!=true && bound > 0 && ex==false)
	{
		int r, c, w[3][3] = { {0,0,0},{0,0,0},{0,0,0} }, x[3][3]= { {0,0,0},{0,0,0},{0,0,0} }, y[3][3]= { {0,0,0},{0,0,0},{0,0,0} }, z[3][3]= { {0,0,0},{0,0,0},{0,0,0} };
		bool f,f1,f2,f3,f4;
		assign(a, w);	
		assign(a, x);
		assign(a, y);	
		assign(a, z);
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (a[j][k] == 0)
				{
					r = j;
					c = k;
				}
			}
		}
		if (r == 0 && c == 0)
		{
		//	print(a,bound);
			swap(w[r + 1][c], w[r][c]);
			f1=DLS(w, bound - 1);
			swap(x[r][c], x[r][c+1]);
			f2 = DLS(x, bound - 1);
			if (f1 || f2)
			{
				f = true;
			}
		}
		else if (r == 0 && c == 1)
		{
		//	print(a,bound);
			swap(w[r + 1][c], w[r][c]);
			f1 = DLS(w, bound - 1);
			swap(x[r][c], x[r][c + 1]);
			f2 = DLS(x, bound - 1);
			swap(y[r][c-1], y[r][c]);
			f3 = DLS(y, bound - 1);
			if (f1 || f2 ||f3)
			{
				f = true;
			}
		}
		else if (r == 0 && c == 2)
		{
		//	print(a,bound);
			swap(w[r + 1][c], w[r][c]);
			f1 = DLS(w, bound - 1);
			swap(x[r][c], x[r][c - 1]);
			f2 = DLS(x, bound - 1);
			if (f1 || f2)
			{
				f = true;
			}
		}
		else if (r == 1 && c == 0)
		{
		//	print(a,bound);
			swap(w[r - 1][c], w[r][c]);
			f1 = DLS(w, bound - 1);
			swap(x[r+1][c], x[r][c]);
			f2 = DLS(x, bound - 1);
			swap(y[r][c+1], y[r][c]);
			f3 = DLS(y, bound - 1);
			if (f1 || f2 || f3)
			{
				f = true;
			}
		}
		else if (r == 1 && c == 1)
		{
		//	print(a,bound);
			swap(w[r + 1][c], w[r][c]);
			f1 = DLS(w, bound - 1);
			swap(x[r - 1][c], x[r][c]);
			f2 = DLS(x, bound - 1);
			swap(y[r][c - 1], y[r][c]);
			f3 = DLS(y, bound - 1);
			swap(z[r][c + 1], z[r][c]);
			f4 = DLS(z, bound - 1);
			if (f1 || f2 || f3 || f4)
			{
				f = true;
			}
		}
		else if (r == 1 && c == 2)
		{			
		//	print(a,bound);
			swap(w[r + 1][c], w[r][c]);
			f1 = DLS(w, bound - 1);
			swap(x[r - 1][c], x[r][c]);
			f2 = DLS(x, bound - 1);
			swap(y[r][c - 1], y[r][c]);
			f3 = DLS(y, bound - 1);
			if (f1 || f2 || f3)
			{
				f = true;
			}
		}
		else if (r == 2 && c == 0)
		{
		//	print(a,bound);
			swap(x[r - 1][c], x[r][c]);
			f2 = DLS(x, bound - 1);
			swap(z[r][c + 1], z[r][c]);
			f4 = DLS(z, bound - 1);
			if (f2 || f4)
			{
				f = true;
			}
		}
		else if (r == 2 && c == 1)
		{
		//	print(a,bound);
			swap(x[r - 1][c], x[r][c]);
			f2 = DLS(x, bound - 1);
			swap(y[r][c - 1], y[r][c]);
			f3 = DLS(y, bound - 1);
			swap(z[r][c + 1], z[r][c]);
			f4 = DLS(z, bound - 1);
			if (f2 || f3 || f4)
			{
				f = true;
			}
		}
		else if (r == 2 && c == 2)
		{
		//	print(a,bound);
			swap(x[r - 1][c], x[r][c]);
			f2 = DLS(x, bound - 1);
			swap(y[r][c - 1], y[r][c]);
			f3 = DLS(y, bound - 1);
			if (f2 || f3)
			{
				f = true;
			}
		}
		if (f == true)
		{
			return true;
		}
	}
	else 
		return false;
}

int main()
{
	int puzzle[3][3] = { {1,2,3},{4,5,6},{0,8,7} };
	int depth;
	cout<<"Enter Depth Bound:";
	cin>>depth;
	g=depth;
	bool flag=false;
	for (int i = 0; i <= depth; i++)
	{
		cout<<"iteration:  "<<i<<endl;
		flag = DLS(puzzle, i);
		if (flag == true){
		cout << "solved in iteration!\n"<<i<<endl;
		exit(0);
		}
	}
	//if(flag=false)
		cout<< "unsolved!\n";
	return 0;

}


