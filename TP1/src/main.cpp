#include "../include/FileReader.h"
#include "../include/Formula.h"
#include "../include/Solver.h"

int main()
{
    FileReader reader = FileReader("input.txt");
    Solver solver = Solver();

    for(int i = 0; i < reader.GetSize(); i++)
    {
        solver.Execute(reader.GetCommand(i));
    }

   /*  char * str = "0";
    Node<char*> * node0 = new Node(str);
    str = "1";
    Node<char*> * node1 = new Node(str);
    str = "2";
    Node<char*> * node2 = new Node(str);
    str = "3";
    Node<char*> * node3 = new Node(str);
    str = "4";
    Node<char*> * node4 = new Node(str);
    str = "5";
    Node<char*> * node5 = new Node(str);
    str = "6";
    Node<char*> * node6 = new Node(str);

    node4->setLeft(node6);
    node4->setRigth(node5);
    node2->setLeft(node4);
    node2->setRigth(node3);
    node0->setLeft(node2);
    node0->setRigth(node1);

    BinaryTree tree = BinaryTree();

    tree.insert(node0); */

    return 0;
}