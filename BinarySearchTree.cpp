//Binary Search Tree

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *rchild;
    struct node *lchild;
}*ROOT, *NEW, *ptr, *ptr1, *parent, *lmost;
void preorder(struct node *point){
    if(point != NULL){
        printf("%d\t", point->data);
        if(point->lchild != NULL)
            preorder(point->lchild);
        if(point->rchild != NULL)
            preorder(point->rchild);
    }
    else{
        return;
    }
}
void postorder(struct node *point){
    if(point != NULL){
        if(point->lchild != NULL)
            inorder(point->lchild);
        if(point->rchild != NULL)
            inorder(point->rchild);
        printf("%d\t",point->data);
    }
}
void inorder(struct node *point){
    if(point != NULL){
        if(point->lchild != NULL)
            inorder(point->lchild);
        printf("%d\t",point->data);
        if(point->rchild != NULL)
            inorder(point->rchild);
    }
}
void search_bst(int value){
    if(ROOT == NULL)
        printf("Empty tree.\n");
    else{
        ptr = ROOT;
        int flag = 0;
        while(ptr != NULL){
            if(ptr->data == value){
                flag = 1;
                break;
            }
            else if(ptr->data > value)
                ptr = ptr->lchild;
            else
                ptr = ptr->rchild;
        }
        if(flag == 1)
            printf("Item is found.\n");
        else
            printf("Item does not exist.\n");
    }
}
void insert_bst(int value){
    NEW = (struct node*)malloc(sizeof(struct node));
    NEW->data = value;
    NEW->lchild = NULL;
    NEW->rchild = NULL;
    if(ROOT == NULL)
        ROOT = NEW;
    else{
        ptr = ROOT;
        ptr1 = NULL;
        int flag = 0;
        while(ptr != NULL){
            if(ptr->data == value){
                flag = 1;
                printf("Data already exists.\n");
                break;
            }
            else if(ptr->data > value){
                ptr1 = ptr;
                ptr = ptr->lchild;
            }
            else{
                ptr1 = ptr;
                ptr = ptr->rchild;
            }
        }
        if(flag == 1)
            return;
        else{
            if(ptr1->data > NEW->data)
                ptr1->lchild = NEW;
            else
                ptr1->rchild = NEW;
        }
    }
}
int delete_bst(int value){
    if(ROOT == NULL)
        printf("Empty tree.\n");
    else if(ROOT->lchild == NULL && ROOT->rchild == NULL){
        int inf = ROOT->data;
        ROOT = NULL;
        return inf;
    }
    else{
        parent = ROOT;
        ptr = ROOT;
        int flag = 0;
        while(ptr->data != value){
            if(ptr->data > value){
                parent = ptr;
                ptr = ptr->lchild;
            }
            else{
                parent = ptr;
                ptr = ptr->rchild;
            }
        }
        int delete_choice;
        if(ptr->lchild == NULL && ptr->rchild == NULL)
            delete_choice = 1;
        else if(ptr->lchild != NULL && ptr->rchild != NULL)
            delete_choice = 3;
        else
            delete_choice = 2;
        if(delete_choice == 1){
            if(parent->lchild == ptr)
                parent->lchild = NULL;
            else
                parent->rchild = NULL;
            return ptr->data;
        }
        else if(delete_choice == 2){
            if(parent == ptr){
                if(ptr->lchild == NULL){
                    parent = ptr->rchild;
                    ROOT = parent;
                }
                else{
                    parent = ptr->lchild;
                    ROOT = parent;
                }
            }
            else{
                if(parent->lchild == ptr){
                    if(ptr->lchild == NULL)
                        parent->lchild = ptr->rchild;
                    else
                        parent->lchild = ptr->lchild;
                }
                else{
                    if(ptr->lchild == NULL)
                        parent->rchild = ptr->rchild;
                    else
                        parent->rchild = ptr->lchild;
                }
            }
            return ptr->data;
        }
        else{
            int info = ptr->data;
            lmost = NULL;
            lmost = ptr->rchild;
            while(lmost->lchild != NULL)
                lmost = lmost->lchild;
            parent = ptr;
            int info1 = lmost->data;
            delete_bst(lmost->data);
            parent->data = info1;
            return info;
        }
    }
}
int main(){
    int value, selection, deleted_value;
    int c;
    while(1){
        printf("Enter\n1 to search\n2 to insert\n3 to delete\n4 to exit\n");
        scanf("%d", &selection);
        switch(selection){
            case 1:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search_bst(value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_bst(value);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleted_value = delete_bst(value);
                printf("The value deleted is %d", deleted_value);
                break;
            default:
                exit(0);
        }
        printf("\nPreorder\n");
        preorder(ROOT);
        printf("\nInorder\n");
        inorder(ROOT);
        printf("\nPostorder\n");
        postorder(ROOT);
        printf("\n");
    }
    return 0;
}
