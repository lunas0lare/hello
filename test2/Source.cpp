#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct node
{
	string data;
	node* left;
	node* right;
};

struct ques
{
	string flag;
	string question;
};
void insert(node*& t, string x)
{
	if (t == NULL)
	{
		t = new node;
		t->data = x;
		t->right = NULL;
		t->left = NULL;
	}
	else
	{
		if (x > t->data)
			insert(t->right, x);
		else
			insert(t->left, x);
	}
}

int file_size(const char* filein)
{
	string s;
	int n = 0;
	ifstream fi(filein, ios::in);
	while (!fi.eof())
	{
		getline(fi, s, '\n');
		n++;
	}
	fi.close();
	return n;
}

void readfile(const char* filein, int n, ques*& a)
{
	ifstream fi(filein, ios::in);

	a = new ques[n + 10];
	int count = 0;
	string s = "";
	while (!fi.eof())
	{
		getline(fi, s, '\n');
		a[count].flag = s.substr(0, s.find(" "));
		a[count].question = s.substr(s.find(" ") + 2, s.size());
		count++;
	}
	fi.close();
}

void BinaryTree(node* t, ques* a, int& i, int n)
{
	if (i < n)
	{
		if (a[i].flag == "A" && t == NULL)
		{
			t = new node;
			t->data = a[i].flag;
			t->right = NULL;
			t->left = NULL;
			i++;
			return;
		}
		else if (a[i].question == "Q" && t == NULL)
		{
			t = new node;
			t->data = a[i].question;
			t->right = NULL;
			t->left = NULL;
			i++;
		}
		BinaryTree(t->left, a, i, n);
		BinaryTree(t->right, a, i, n);
	}
}

void print(node* t)
{
	if (t != NULL)
	{
		cout << t->data << endl;
		print(t->left);
		print(t->right);
	}
}

int main()
{
	node* t = NULL;
	string s;
	ques* a = NULL;
	int  i = 0;
	int count = file_size("animal.txt");
	readfile("animal.txt", count, a);
	BinaryTree(t, a, i, count);
	//cout << "hello";
	print(t);
	return 0;
}