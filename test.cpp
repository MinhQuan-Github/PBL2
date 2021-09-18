#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <cstring.h>
#include <stdio.h>
#define M 26  // so Buckets
 
class Dictionary;
class Node  // lop node
{
    private:
    char word[100];  // truong word la mot tu tieng anh
      char mean[100];  // truong mean la nghia cua tu
      Node *next;      // truong next chi nut tiep theo khi nut bi xung dot
   public:
    Node();
      Node (Node *k);
      Node(char nword[],char nmean[]);
      Node(char nWord[]);
      void displayWord();
      void displayMeaning();
      void Input();
   friend class Dictionary;
};
 
void Node::Input()             // Ham nhap tu va nghia cho Node
{
    cout<<"\nInput word: ";
    gets(word);
    cout<<"Mean: ";
    gets(mean);
};
 
void Node::displayWord()
{
    cout<<"\n\t\tWord:"<<word;
}
 
void Node::displayMeaning()
{
    cout<<"\t\tMean:"<<mean;
}
 
Node::Node(char nWord[])
{
    strcpy(word,nWord);
    next=NULL;
}
 
Node::Node(char nword[],char nmean[])
{
    for(int i = 0;i < 100; i++)
    {
        word[i] = '\0';
        mean[i] = '\0';
    }
    strcpy(word,nword);
    strcpy(mean,nmean);
    next = NULL;
}
 
Node::Node()
{
    for(int i = 0;i < 100; i++)
    {
        word[i] = '\0';
        mean[i] = '\0';
    }
   next = NULL;
};
 
Node::Node(Node *k)
{
    for(int i = 0;i < 100; i++)
    {
        word[i] = '\0';
        mean[i] = '\0';
    }
    strcpy(word,k->word);
   strcpy(mean,k->mean);
   next = NULL;
}
 
class Dictionary   /////////////////////////////////////////////////// lop tu dien
{
    private:
      Node *Bucket[M]; // Mang cac bucket
   public:
    Dictionary();
 
      bool Isempty();                         // Kiem tra xem bang bam co rong khong
 
    int  HashFunc(char c);                      // Ham bam
 
      void Insert(char nWord[],char nMean[]); // Ham nay de chen ca word va mean vao bang bam
      void Insert (Node *k);                        // Ham nay de chen khoa k vao bang bam
      void Place (int b, Node *k);             // Ham nay de chen Node k vao bucket thu b
 
        void FindNode(int key,Node *k);           // Tim theo key
      void Find(char word[]);                  // Tim theo tu
 
      void DeleteNode(int key, Node *k);       // Xoa theo key
      void Delete(char word[]);                // Xoa theo tu
 
      void Display();                                // Duyet toan bo bucket
};
 
bool Dictionary::Isempty()
{
    int dem = 0;
    for(int i = 0;i < M;i++)
   {
        if(Bucket[i] != NULL)
        dem ++;
   }
   if(dem == 0)
    return true;
   else
    return false;
}
 
Dictionary::Dictionary()
{
    for(int i = 0;i < M;i ++)
    {
        Bucket[i] = 0;
    }
}
 
void Dictionary::DeleteNode(int key,Node *k)
{
    Node *temp = Bucket[key];
   Node *node = Bucket[key];
   if(node == NULL)
   {
    cout<<"Khong co tu nay ";
   }
   else
   {
      if(strcmpi(Bucket[key]->word,k->word)==0)
    {
        Bucket[key] = Bucket[key]->next;
    }
    while(temp != NULL)
    {
            if(strcmpi(temp->word,k->word) == 0)
            break;
        node = temp;
        temp = temp->next;
      }
      if(temp != NULL)
      {
            node->next = temp->next;
         node = NULL;
        delete node;
        temp->next = NULL;
        delete temp;
      }
      else
        cout<<"Khong co tu nay ";
   }
}
 
void Dictionary::Delete(char nWord[])
{
    if(Isempty() == true)
    cout<<"\nTu Dien rong \n";
    int t = HashFunc(nWord[0]);
   Node * temp = new Node(nWord);
   DeleteNode(t,temp);
}
 
void Dictionary::FindNode(int key,Node * newnode)
{
        if(Bucket[key]==NULL)
      {
        cout<<"Khong co tu nay!"<<endl;
      }
      else
      {
        Node * temp = Bucket[key];
        int d = 0;
        while(temp!=NULL)
        {
            if(strcmpi(temp->word,newnode->word) == 0)
            {
                temp->displayWord();
                temp->displayMeaning();
               d++;
            }
            temp=temp->next;
        }
        if (d == 0)
        {
            cout<<endl<<"Khong co tu nay!"<<endl;
        }
      }
};
 
void Dictionary::Find(char nWord[])
{
    if(Isempty())
    cout<<"\nTu Dien rong: \n";
    int t = HashFunc(nWord[0]);
   Node * temp = new Node(nWord);
   FindNode(t,temp);
};
 
int Dictionary::HashFunc(char c)    // Ham bam (neu ky tu la a thi tra ve 0 ..... z thi tra ve 25)
{
    int a=c;
    if (a >= 97)       // su dung bang ma ASCII
        a = a - 32;
    return (a % 65);
};
 
 
void Dictionary::Place(int b, Node *k)  // Ham nay de chen Node k vao bucket thu b
{
    if (Bucket[b] == 0)
   {
    Bucket[b] = k;
   }
   else
   {
    Node * temp = Bucket[b];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = k;
   }
};
 
void Dictionary::Insert(char nWord[],char nMean[])   // Ham insert nghia va tu vao bucket
{
    Node * newNode = new Node(nWord,nMean);
    int t = HashFunc(nWord[0]);
    Place(t,newNode);
};
 
void Dictionary::Insert(Node *k)         // Ham insert mot Node vao bucket
{
    int b ;
   b = HashFunc(k->word[0]);
   Place(b,k);
};
 
void Dictionary::Display()                         // Duyet toan bo bucket
{
    if(Isempty() == true)
    cout<<"\nTu Dien rong \n";
    Node * temp;
    for (int i=0;i<M;i++)
   {
        temp = Bucket[i];
        while(temp!=NULL)
        {
            temp->displayWord();
            temp->displayMeaning();
         cout<<endl;
            temp = temp->next;
        }
   }
};
 
void Menu(Dictionary &td)
{
    int choice;
    cout<<"\t\t\t    Tu dien ung dung Bang Bam"<<endl<<endl;
   cout<<"\t\t\t    1/. Them tu khoa vao cay "<<endl<<endl;
   cout<<"\t\t\t    2/. Xoa Bot tu khoa "<<endl<<endl;
   cout<<"\t\t\t    3/. Tra cuu tu "<<endl<<endl;
   cout<<"\t\t\t    4/. Hien thi cay hien tai "<<endl<<endl;
   cout<<"\t\t\t    5/. De thoat khoi chuong trinh "<<endl<<endl<<endl;
   cout<<"\t\t\t      Moi ban chon mot chuc nang  ";
   cin>>choice;
   switch(choice)
   {
    case 1:
    {
        int n;
        system("cls");
         cout<<"\nBan muon chen bao nhieu tu khoa: ";
         cin>>n;
         for(int i = 0;i < n;i++)
         {
            Node *data=new Node;
            data->Input();
            td.Insert(data);
         }
         cout<<"\n\n Tu Dien sau khi da chen\n";
         td.Display();
         getch();
         system("cls");
         Menu(td);
      }
      case 2:
      {
        system("cls");
         char word[100];
         cout<<endl;
         cout<<"Nhap tu muon xoa: ";
         gets(word);
         td.Delete(word);
         cout<<endl<<"\nDanh sach sau khi xoa:";
         td.Display();
         getch();
         system("cls");
         Menu(td);
      }
      case 3:
      {
        system("cls");
         char word[100];
         cout<<endl;
         cout<<"Nhap tu muon tim: ";
         gets(word);
         td.Find(word);
         getch();
         system("cls");
         Menu(td);
      }
      case 4:
      {
        system("cls");
        td.Display();
         getch();
         system("cls");
         Menu(td);
      }
      case 5:
      {
        exit(0);
      }
      default:
    {
        system("cls");
        cout<<"\n\tKhong co chuc nang nay: ";
         getch();
         system("cls");
         Menu(td);
      }
   }
 
};
 
void main()
{
   textmode(C4350);// noi rong man hinh
    Dictionary td;
    Menu(td);
};
