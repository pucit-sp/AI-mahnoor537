#include <iostream>
#include <vector>
using namespace std;

static bool ex=false;
struct board
{
    int symbol[3][3];
};
vector<board> v;

void assign(struct board &new1,struct board &new2)
{
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{	
			new2.symbol[i][j]= new1.symbol[i][j];
		}
	}
}
void print(struct board new1,int bound)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<" "<<new1.symbol[i][j]<<"  "; 
			if (j == 2)
				cout << " \n";
		}
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

bool goal(struct board &new1)
{
	if (new1.symbol[0][0] == 1 && new1.symbol[0][1] == 8 && new1.symbol[0][2] == 7 && new1.symbol[1][0] == 2 && new1.symbol[1][1] == 0 && new1.symbol[1][2] == 6 && new1.symbol[2][0] == 3 && new1.symbol[2][1] == 4 && new1.symbol[2][2] == 5) 
		{	
		    cout<<"\nGOAL STATE FOUND!!\n\n=>PATH:\n";
			return true;
		}
	else
		return false;

}
bool DIFD(struct board &new1, int bound)
{	int check=0;
	bool ch=false;
	ch=goal(new1);
	if (ch==true && bound>=0)
	{
		ex=true;
		v.push_back(new1);
		struct board display;
		int a=v.size();
		cout<<"\nsize:::::::::::::::::"<<a<<endl<<endl<<endl;
		for(int i=0;i<a;i++)
		{
			display=v[i];
			print(display,bound);
		}
		return true;
	}
	if (ch!=true && bound > 0 && ex==false)
	{
		int r, c;
		struct board w,x,y,z;
		bool f,f1,f2,f3,f4;
		assign(new1, w);	
		assign(new1, x);
		assign(new1, y);	
		assign(new1, z);

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (new1.symbol[j][k] == 0)
				{
					r = j;
					c = k;
				}
			}
		}
		if (r == 0 && c == 0)
		{
			swap(w.symbol[r + 1][c], w.symbol[r][c]);
			v.push_back(new1);
			f1=DIFD(w, bound - 1);
			swap(x.symbol[r][c], x.symbol[r][c+1]);
			v.push_back(new1);
			f2 = DIFD(x, bound - 1);
			if (f1 || f2)
			{
				f = true;
			}
		}
		else if (r == 0 && c == 1)
		{
			swap(w.symbol[r + 1][c], w.symbol[r][c]);
			v.push_back(new1);
			f1 = DIFD(w, bound - 1);
			swap(x.symbol[r][c], x.symbol[r][c + 1]);
			v.push_back(new1);
			f2 = DIFD(x, bound - 1);
			swap(y.symbol[r][c-1], y.symbol[r][c]);
			v.push_back(new1);
			f3 = DIFD(y, bound - 1);
			if (f1 || f2 ||f3)
			{
				f = true;
			}
		}
		else if (r == 0 && c == 2)
		{
			swap(w.symbol[r + 1][c], w.symbol[r][c]);
			v.push_back(new1);
			f1 = DIFD(w, bound - 1);
			swap(x.symbol[r][c], x.symbol[r][c - 1]);
			v.push_back(new1);
			f2 = DIFD(x, bound - 1);
			if (f1 || f2)
			{
				f = true;
			}
		}
		else if (r == 1 && c == 0)
		{
			swap(w.symbol[r - 1][c], w.symbol[r][c]);
			v.push_back(new1);
			f1 = DIFD(w, bound - 1);
			swap(x.symbol[r+1][c], x.symbol[r][c]);
			v.push_back(new1);
			f2 = DIFD(x, bound - 1);
			swap(y.symbol[r][c+1], y.symbol[r][c]);
			v.push_back(new1);
			f3 = DIFD(y, bound - 1);
			if (f1 || f2 || f3)
			{
				f = true;
			}
		}
		else if (r == 1 && c == 1)
		{
			swap(w.symbol[r + 1][c], w.symbol[r][c]);
			v.push_back(new1);
			f1 = DIFD(w, bound - 1);
			swap(x.symbol[r - 1][c], x.symbol[r][c]);
			v.push_back(new1);
			f2 = DIFD(x, bound - 1);
			swap(y.symbol[r][c - 1], y.symbol[r][c]);
			v.push_back(new1);
			f3 = DIFD(y, bound - 1);
			swap(z.symbol[r][c + 1], z.symbol[r][c]);
			v.push_back(new1);
			f4 = DIFD(z, bound - 1);
			if (f1 || f2 || f3 || f4)
			{
				f = true;
			}
		}
		else if (r == 1 && c == 2)
		{			
			swap(w.symbol[r + 1][c], w.symbol[r][c]);
			v.push_back(new1);
			f1 = DIFD(w, bound - 1);
			swap(x.symbol[r - 1][c], x.symbol[r][c]);
			v.push_back(new1);
			f2 = DIFD(x, bound - 1);
			swap(y.symbol[r][c - 1], y.symbol[r][c]);
			v.push_back(new1);
			f3 = DIFD(y, bound - 1);
			if (f1 || f2 || f3)
			{
				f = true;
			}
		}
		else if (r == 2 && c == 0)
		{
			swap(x.symbol[r - 1][c], x.symbol[r][c]);
			v.push_back(new1);
			f2 = DIFD(x, bound - 1);
			swap(z.symbol[r][c + 1], z.symbol[r][c]);
			v.push_back(new1);
			f4 = DIFD(z, bound - 1);
			if (f2 || f4)
			{
				f = true;
			}
		}
		else if (r == 2 && c == 1)
		{
			swap(x.symbol[r - 1][c], x.symbol[r][c]);
			v.push_back(new1);
			f2 = DIFD(x, bound - 1);
			swap(y.symbol[r][c - 1], y.symbol[r][c]);
			v.push_back(new1);
			f3 = DIFD(y, bound - 1);
			swap(z.symbol[r][c + 1], z.symbol[r][c]);
			v.push_back(new1);
			f4 = DIFD(z, bound - 1);
			if (f2 || f3 || f4)
			{
				f = true;
			}
		}
		else if (r == 2 && c == 2)
		{
			swap(x.symbol[r - 1][c], x.symbol[r][c]);
			v.push_back(new1);
			f2 = DIFD(x, bound - 1);
			swap(y.symbol[r][c - 1], y.symbol[r][c]);
			v.push_back(new1);
			f3 = DIFD(y, bound - 1);
			if (f2 || f3)
			{
				f = true;
			}
		}
		if (f == true)
		{
			return true;
		}
		else 
		{
			while (!v.empty())
				v.pop_back();
		}
	}
	return false;
}

int main()
{
	board puzzle;
	puzzle.symbol[0][0]=2;
	puzzle.symbol[0][1]=1;
	puzzle.symbol[0][2]=7;
	puzzle.symbol[1][0]=0;
	puzzle.symbol[1][1]=8;
	puzzle.symbol[1][2]=6;
	puzzle.symbol[2][0]=3;
	puzzle.symbol[2][1]=4;
	puzzle.symbol[2][2]=5;

	int depth;
	cout<<"Enter Depth Bound:";
	cin>>depth;
	bool flag=false;
	for (int i = 0; i <= depth; i++)
	{
		cout<<"iteration:  "<<i<<endl;
		flag = DIFD(puzzle, i);
		if (flag == true)
		{
			cout << "SOLVED IN ITERATION->!\n"<<i<<endl;
			exit(0);
		}
	}
		cout<< "UNSOLVED!\n";
	return 0;
}


