#include <bits/stdc++.h>

using namespace std;

typedef struct tagNode{ // Node: gồm kiểu dữ liệu và địa chỉ của phần tử kế tiếp
    int info;
    struct tagNode *pNext;
}Node;
typedef struct tagList{
    Node *pHead; // Trỏ tới phần tử ở đầu danh sách
    Node *pTail; // Trỏ tới phần tử ở cuối danh sách
}LIST;

LIST L;
void CreateList(LIST &L){ // Tạo một list rỗng
    L.pHead = NULL;
    L.pTail = NULL;
}
void PrintList(LIST L){ // Duyệt + in ra các phần tử trong list
    Node *p;
    p = L.pHead;
    while(p != NULL){
        cout << p->info << ' ';
        p = p->pNext;
    }
}
Node* CreateNode(int x){ // Tạo Node cho dữ liệu vào
    Node *p;
    p = new Node;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddHead(LIST &L, Node *p){ // Thêm phần tử vào đầu danh sách
    if (L.pHead == NULL){
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}
void AddTail(LIST &L, Node *p){ // Thêm phần tử vào cuối danh sách
    if (L.pHead == NULL){
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
Node *Search(LIST L, int x){ // Tím phần tử x trong list, trả về địa chỉ của Node có info = x
    Node *p;
    p = L.pHead;
    while((p != NULL) && (p->info != x)){
        p = p->pNext;
    }
    return p; // Trả về Nu
}
void InsertAfterQ(LIST &L, Node *p, Node *q){ // chèn phần tử p sau phần tử q
    if (q != NULL){
        p->pNext = q->pNext;
        q->pNext = p;
        if (L.pTail == q) L.pTail = p;
    }
    else AddHead(L, q);
}
int DeleteAfterQ(LIST &l, Node *q, int &x){ // Bỏ phần tử phía sau q
    Node *p;
    if (q != NULL){
        p = q->pNext;
        if (p != NULL){
            if (p == l.pTail)
                l.pTail = q;
            q->pNext = p->pNext;
            x = p->info;
            delete p;
        }
        return 1;
    }
    else return 0;
}
int RemoveHead(LIST &L, int &x){ // Bỏ phần tử ở đầu list
    Node *p;
    if (L.pHead != NULL){
        p = L.pHead;
        x = p->info;
        L.pHead = L.pHead->pNext;
        delete p;
        if (L.pHead == NULL)
            L.pTail = NULL;
        return 1;
    }
    return 0;
}
int RemoveX(LIST &L, int x){ // Bỏ phần tử có info = x trong list
    Node *p, *q = NULL;
    p = L.pHead;
    while((p != NULL) && (p->info != x)){
        q = p;
        p = p->pNext;
    }
    if (p == NULL) return 0;
    if (q != NULL) DeleteAfterQ(L, q, x);
    else RemoveHead(L, x);
    return 1;
}
int RemoveAllX(LIST &L, int x){
    while(1){
        Node *px = Search(L, x);
        if (px == NULL) break;
        RemoveX(L, x);
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    CreateList(L);
    int t;
    while(cin >> t){
        if (t == 6) break;
        if (t == 0){
            int x; cin >> x;
            Node *p = CreateNode(x);
            AddHead(L, p);
        }
        if (t == 1){
            int x; cin >> x;
            Node *p = CreateNode(x);
            AddTail(L, p);
        }
        if (t == 2){
            int x, y;
            cin >> x >> y;
            Node *py = CreateNode(y);
            Node *px = Search(L, x);
            if (px != NULL) InsertAfterQ(L, py, px);
            else AddHead(L, py);
        }
        if (t == 3) {
            int x; cin >> x;
            RemoveX(L, x);
        }
        if (t == 4){
            int x; cin >> x;
            RemoveAllX(L, x);
        }
        if (t == 5) RemoveHead(L, t);
    }

    if (L.pHead == NULL && L.pTail == NULL) cout << "blank";
    else
        PrintList(L);

    return 0;
}
