#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>
 
#define VER 50
#define SIZE 20
 
#define FALSE 0
#define TRUE 1
using namespace std;
class Derevo
{
private:
        char Sename[SIZE];
        Derevo *left;
        Derevo *right;
        float data;
public:
        void set(char *p1, float k, Derevo **node, Derevo num1)
                {
                strcpy (Sename, p1);
                data=k;
                Insert(Sename, data, &*node, num1);
                }
        void Insert(char *Sename, float data, Derevo **node, Derevo num1)
                {
                if (*node == NULL)                                      /// ���� node � ������� ��������� 
                        {
                        *node= new Derevo;                              /// ������� ����� ����
                        strcpy((*node)->Sename, Sename);
                        (*node)->data = data;
                        (*node)->left = (*node)->right = NULL;
                        }
                else
                        {
                        if (strcmp(Sename, (*node)->Sename) > 0)
                                Insert(Sename, data, &(*node)->right, num1);
                        else if (strcmp(Sename, (*node)->Sename) < 0)
                                Insert(Sename, data, &(*node)->left, num1);
                        else
                                cout<<"\n There is such element in the tree";
                        }
                }
        void Delete(Derevo **node, float val, Derevo num1)
                {
                if (*node == NULL)
                        {
                        cout<<"\n There is not such element";
                        }
                if      ((*node)->data < val)
                        Delete(&(*node)->right, val, num1);
                else if ((*node)->data > val)
                        Delete(&(*node)->left, val, num1);
                else
                        {
                        Derevo *left = (*node)->left, *right = (*node)->right;
                        free(*node);
                        if (left == NULL)
                                *node = right;
                        else if (right == NULL)
                                *node = left;
                        else
                                {
                                *node = left;
                                while (left->right != NULL)
                                        left = left->right;
                                left->right = right;
                                }
                        }
                }
        void View(Derevo *node)
                {
                if (node->left)
                        View(node->left);
 
                cout<<" "<<node->Sename<<" "<<node->data<<'\n';
 
                if (node->right)
                        View(node->right);
                }
        int strcmp (char *s1, char *s2)         /// ������� ��� ��������� ���������
            {                                   /// ��������� �������� ��������
            for (; *s1==*s2 ; s1++, s2++)
                if (!*s1) return 0;
                    return *s1-*s2;
                }
};
 
int main(void)
{
system("cls");
int i=0, j=0, input;
Derevo *root=NULL;
Derevo num1[VER];
char p1[100], p2[100];
float k, key;
int done = FALSE;
char d;
 
while (!done)
        {
        system("cls");
        cout<<"\n\n I)nsert, D)elete, V)iew, Q)uit:  ";
    d = toupper (getchar());
    switch (d)
            {
                case 'I':
                        cout<<"\n Enter file name and date: ";
                        cin>>p1;
                        cin>>k;
                        num1[1].set(p1, k, &root, *num1);
                        i++, j++;
                        cout<<"\n Element added. Press any key...";
                        getch();
                        break;
                case 'D':
                        cout<<"\n Enter date: "; cin>>input;
                        num1[1].Delete(&root, input, *num1);
                        j--;
                        cout<<"\n Element udalen. Press any key...";
                        getch();
                        break;
                case 'V':
                        if (root)
                                {
                                cout<<"\n Vyvod ishodnogo dereva: \n\n";
                                num1[1].View(root);
                                cout<<"\n Press any key...";
                                getch();
                                }
                        else    {
                                cout<<"\n Tree is empty";
                                getch();
                                }
                        break;
                case 'Q':
                done = TRUE;
                break;
                }
    }
return 0;
}
 