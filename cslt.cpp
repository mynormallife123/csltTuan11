


//remove head
void removeHead(list &l) {
  if (l.head != nullptr) { 
    node* ptr = l.head;
    l.head = l.head->next;
    delete l.ptr;
  }
  else
    return;
}

//remove tail
void removeTail(list &l) {
  if (l.head == nullptr)
    return;
  if (l.head->next == nullptr) {
    delete l.head;
    return;
  }
  else {
    node* previousNode = nullptr;
    for (auto p = l.head; p; prev = p, p = p->next) {
      if (!p->next) {
        previousNode->next = p->next;
        delete p;
      }
    }
  }
}

//important technique (by Linus Torvald - Linux's creator)
//related to pointer of pointer:

for (node** p = &l.head; *p; p = (*p)->next) {
  if (!*p) {
    ...
  }
}

//remove middle
void removeMiddle(list &l) {
  if (!l.head) //l.head = nullptr
    return;
  if (!l.head->next) //linked list has one element
    return;
  if (!l.head->next->next)
    return;
  if 
}

//remove all
void removeAll(list &l) {
  while (!isEmpty(l))
    removeHead(l);
}

//homework: implement ALL OPERATIONS STUDIED ON doubly linked list





//Thi lý thuyết CSLT làm bài tự luận trên giấy
//Thời gian: 90p
//Nội dung (đề riêng - khó hơn rất nhiều, mỗi câu 2đ):
//1. Rẽ nhánh (if - else), lặp (for - while)
//2. Mảng, chuỗi (1D) (tĩnh & động)
//3. Mảng 2 chiều
//4. Danh sách liên kết (đơn)
//5. Tập tin (văn bản, nhị phân) (.jpg??)
//văn bản: f >>, f <<, fscanf, fprintf
//nhị phân: f.read, f.write hoặc fread, fwrite; fseek (f.seekg)
//C++
//<iostream>
//<fstream>
//<sstream>
//C:
//<stdio.h>
//<math.h>
//<ctype.h>
//<time.h>
//<stdlib.h>
//<stdint.h>
//<string.h>
//trước khi viết hàm, nên có 1-2 dòng chú thích hàm làm gì
//được viết hàm phụ hỗ trợ hàm chính
//được sử dụng tài liệu tham khảo = 1 tờ A4 VIẾT TAY

//ko được dùng std::vector, std::string, std::list, 














    
