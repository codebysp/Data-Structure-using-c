#include"DLL.h"

void Display(PNODE head)
{
    printf("\n----------------------------------------------------------\n");
    while(head != NULL)
    {
        printf("[%d]->",head->data);
        head=head->next;
    }
    printf("NULL\n----------------------------------------------------------");
}

int Count(PNODE head)
{
    int iCnt=0;
    while(head != NULL)
    {
        head=head->next;
        iCnt++;
    }
    return iCnt;
}
void InsertFirst(PPNODE head,int iNo)
{
    PNODE newn = NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if((*head) == NULL)
    {
        (*head)=newn;
    }
    else
    {
        (*head)->prev=newn;
        newn->next=(*head);
        (*head)=newn;
    }

}

void InsertLast(PPNODE head,int iNo)
{
    PNODE newn = NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;
    PNODE temp = (*head);

    if((*head) == NULL)
    {
        (*head)=newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        newn->prev=temp;
        temp->next=newn;

    }

}

void InsertAtPos(PPNODE head,int iNo,int iPos)
{
    int iSize=Count(*head);
    int iCnt=0;
    if(iPos<1 || iPos>(iSize+1))
    {
        printf("\nInvaild Input\n");
        return;
    }

    PNODE newn = NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;
    PNODE temp = (*head);

    if(iPos==1)
    {
        InsertFirst(head,iNo);
    }
    else if(iPos==iSize)
    {
        InsertLast(head,iNo);
    }
    else
    {
        for(iCnt=1;iCnt<(iPos-1);iCnt++)
        {
            temp=temp->next;
        }
        newn->prev=temp;
        temp->next->prev=newn;
        newn->next=temp->next;
        temp->next=newn;
    }


}

void DeleteFirst(PPNODE head)
{
    
    if((*head) == NULL)
    {
        return;
    }
    else
    {
        (*head)=(*head)->next;
        free((*head)->prev);
        (*head)->prev=NULL;
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp=(*head);
    if((*head) == NULL)
    {
        return;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void DeleteAtPos(PPNODE head,int iPos)
{
    int iSize=Count(*head);
    int iCnt=0;
    if(iPos<1 || iPos>(iSize+1))
    {
        printf("\nInvaild Input\n");
        return;
    }

    PNODE temp = (*head);

    if(iPos==1)
    {
        DeleteFirst(head);
    }
    else if(iPos==iSize)
    {
        DeleteLast(head);
    }
    else
    {
        for(iCnt=1;iCnt<(iPos-1);iCnt++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;
    }
}
int main()
{
    PNODE First = NULL;
    InsertFirst(&First,101);
    InsertFirst(&First,81);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    Display(First);
    int iRet=Count(First);
    printf("\nCount is %d\n",iRet);
    InsertLast(&First,121);
    printf("\nAfter insert Last\n");
    Display(First);
    InsertAtPos(&First,33,4);
    printf("\nAfter Isert At Pos\n");
    Display(First);
    DeleteFirst(&First);
    printf("\nAfter Delet First\n");
    Display(First);
    DeleteLast(&First);
    printf("\nAFter Delet Last\n");
    Display(First);
    DeleteAtPos(&First,4);
    printf("\nAfter delete At pos\n");
    Display(First);

    return 0;
}