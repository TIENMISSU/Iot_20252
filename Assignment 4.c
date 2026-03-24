#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc node theo đề bài
struct node {
    int data;
    struct node* next;
};

// Hàm hỗ trợ: Tạo một node mới
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// (a) Hàm hiển thị tất cả các phần tử của danh sách
void display(struct node* head) {
    struct node* temp = head;
    if (temp == NULL) {
        printf("Danh sach trong.\n");
        return;
    }
    printf("Danh sach: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// (b) Hàm thêm một phần tử vào cuối danh sách
struct node* addback(struct node* head, int data) {
    struct node* newNode = createNode(data);
    
    // Nếu danh sách trống, node mới sẽ là head
    if (head == NULL) {
        return newNode;
    }
    
    // Duyệt đến node cuối cùng
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Thêm node mới vào cuối
    temp->next = newNode;
    
    return head;
}

// (c) Hàm tìm kiếm phần tử có giá trị data cho trước
struct node* find(struct node* head, int data) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp; // Trả về con trỏ tới phần tử tìm thấy
        }
        temp = temp->next;
    }
    return NULL; // Trả về NULL nếu không tồn tại
}

// (d) Hàm xóa phần tử được trỏ bởi pelement
struct node* delnode(struct node* head, struct node* pelement) {
    // Nếu danh sách trống hoặc node cần xóa là NULL
    if (head == NULL || pelement == NULL) {
        return head;
    }

    // Trường hợp đặc biệt: Phần tử cần xóa là phần tử đầu tiên (head)
    if (head == pelement) {
        struct node* newHead = head->next;
        free(head);
        return newHead; // Trả về head mới
    }

    // Duyệt để tìm phần tử đứng ngay trước pelement
    struct node* temp = head;
    while (temp->next != NULL && temp->next != pelement) {
        temp = temp->next;
    }

    // Nếu tìm thấy pelement trong danh sách
    if (temp->next == pelement) {
        temp->next = pelement->next; // Bỏ qua pelement
        free(pelement);              // Giải phóng bộ nhớ
    }

    return head; // Head không thay đổi
}

// (e) Hàm xóa toàn bộ danh sách và giải phóng bộ nhớ
void freelist(struct node* head) {
    struct node* current = head;
    struct node* nextNode;

    while (current != NULL) {
        nextNode = current->next; // Lưu trữ con trỏ tới node tiếp theo
        free(current);            // Giải phóng node hiện tại
        current = nextNode;       // Di chuyển sang node tiếp theo
    }
    printf("Da giai phong toan bo danh sach.\n");
}

// (f) Mã kiểm tra (Test code)
int main() {
    struct node* head = NULL;

    printf("--- Kiem tra ham (b) addback ---\n");
    head = addback(head, 10);
    head = addback(head, 20);
    head = addback(head, 30);
    head = addback(head, 40);
    
    printf("\n--- Kiem tra ham (a) display ---\n");
    display(head);

    printf("\n--- Kiem tra ham (c) find ---\n");
    int searchVal = 30;
    struct node* target = find(head, searchVal);
    if (target != NULL) {
        printf("Tim thay node co gia tri %d\n", target->data);
    } else {
        printf("Khong tim thay node co gia tri %d\n", searchVal);
    }

    printf("\n--- Kiem tra ham (d) delnode (Xoa node 30) ---\n");
    head = delnode(head, target);
    display(head);

    printf("\n--- Kiem tra ham (d) delnode (Xoa head hien tai la 10) ---\n");
    struct node* headNode = find(head, 10);
    head = delnode(head, headNode);
    display(head);

    printf("\n--- Kiem tra ham (e) freelist ---\n");
    freelist(head);
    head = NULL; // Đặt head về NULL sau khi giải phóng để tránh con trỏ treo (dangling pointer)
    display(head); // Kiểm tra lại xem danh sách đã thực sự trống chưa

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc node của cây nhị phân
struct tnode {
    int data;
    struct tnode* left;
    struct tnode* right;
};

// (a) Hàm cấp phát một node mới với dữ liệu cho trước
struct tnode* talloc(int data) {
    struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// (b) Hàm thêm một phần tử vào cây nhị phân tìm kiếm (BST)
struct tnode* addnode(struct tnode* root, int data) {
    // Nếu cây rỗng, tạo node mới làm gốc
    if (root == NULL) {
        return talloc(data);
    }
    
    // Nếu dữ liệu nhỏ hơn node hiện tại, thêm vào nhánh trái
    if (data < root->data) {
        root->left = addnode(root->left, data);
    } 
    // Nếu dữ liệu lớn hơn node hiện tại, thêm vào nhánh phải
    else if (data > root->data) {
        root->right = addnode(root->right, data);
    }
    
    // Trả về con trỏ gốc không đổi
    return root;
}

// (c) Hàm duyệt cây theo thứ tự truoc (Pre-order: Node - Left - Right)
void preorder(struct tnode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// (d) Hàm duyệt cây theo thứ tự giua (In-order: Left - Node - Right)
// Đối với BST, duyệt in-order sẽ in ra các phần tử đã được sắp xếp
void inorder(struct tnode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// (e) Hàm xóa toàn bộ cây và trả về số lượng node đã xóa (dùng Post-order)
int deltree(struct tnode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int count = 0;
    
    // Duyệt post-order: Xóa nhánh trái, xóa nhánh phải, sau đó mới xóa node hiện tại
    count += deltree(root->left);
    count += deltree(root->right);
    
    free(root);
    
    return count + 1; // Cộng 1 cho node vừa được giải phóng
}

// (f) Test code minh họa hoạt động của các hàm trên
int main() {
    struct tnode* root = NULL;

    // Các phần tử cần chèn theo thứ tự đề bài yêu cầu
    int elements[] = {3, 1, 0, 2, 8, 6, 5, 9};
    int n = sizeof(elements) / sizeof(elements[0]);

    printf("--- (b) Dang chen cac phan tu vao cay ---\n");
    for (int i = 0; i < n; i++) {
        root = addnode(root, elements[i]);
        printf("Da chen: %d\n", elements[i]);
    }

    printf("\n--- (c) Duyet Pre-order (Node - Trai - Phai) ---\n");
    printf("Ket qua: ");
    preorder(root);
    printf("\n");

    printf("\n--- (d) Duyet In-order (Trai - Node - Phai) ---\n");
    printf("Ket qua (Da sap xep): ");
    inorder(root);
    printf("\n");

    printf("\n--- (e) Xoa toan bo cay (Post-order) ---\n");
    int deletedNodes = deltree(root);
    root = NULL; // Đặt root về NULL để tránh con trỏ treo
    printf("Da xoa cay thanh cong. Tong so node da xoa la: %d\n", deletedNodes);

    return 0;
}

