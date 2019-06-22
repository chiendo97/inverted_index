# inverted_index

A C++ implementation of Reversed-index search engine and BM25 ranking function.

# Implementation

Trong mỗi thuật toán, tôi sử dụng 2 modules chính để xử lý: preprocessing_document và query. 

- Hàm preprocessing_document sẽ đọc từ ```vector<string> strs``` để tiền xử lý dữ liệu và tạo thành một data structure.
- Hàm query nhận vào một ```string keyword``` để query tìm kiếm và trả về ```vector<string> result``` hoặc ```vector<pair<string, double>> result``` chứa kết quả try vấn.

Ngoài ra ở mỗi chương trình đều có các biến toàn cục để chứa document và data stucture để hỗ trợ việc query.

```
vector<string> strs // chứa các document được đọc từ file input
```

Trong mỗi thuật toán, tôi sử dụng các cấu trúc dữ liệu khác nhau để triền khai và được trình bày dưới đây. 


## Reversed-index

## Trie 

[Trie](https://vnoi.info/wiki/algo/data-structures/trie) là một cấu trúc dữ liệu dùng để quản lý một tập hợp các xâu.

Trong đó mỗi nhánh sẽ chứa 2 giá trị sau đây:
```
// v_set: chứa các docid mà có xuất hiện của keyword
set<int> v_set;
// map: chứa các pointer dẫn đến các nút tiếp theo trong cây Trie
unordered_map<char, Trie*> map;
```

## BM25 ranking function

Trong thuật toán sếp hạng BM25, tôi chỉ sử dụng các data struct của thư viện chuẩn trong C++ bao gồm: map, set, vector. Các cấu trúc được sử dụng kết hợp để tạo này 2 class với 2 mục đích khác nhau.

- InvertedIndex: // tương tự Reversed-index

  - map<string, set<int>> nq; // có bao nhiêu document chứa keyword này
  
  - map<string, map<int, int>> fq; // mỗi document chứa bao nhiêu keyword

- DocumentLengthTable: // quản lý độ dài của mỗi document và độ dài document trung bình



# How To Run

Trong code, có 2 hàm để sử dụng: 

- custom_test(): các query được nhập vào từ bàn phím 
- test_with_100_query(): đọc các query từ file `100_query.txt` và chạy ra kết quả trong file `100_query_result.txt`

Hiện tại mặc định là chạy custom_test(). 

Bạn có thể sửa code thành hàm test_with_100_query() để chạy test với các query từ file.

## Reversed-index

```
cd reversed_index/
g++ -std=c++17 main.cpp -o main && ./main product_names.txt
```

## BM25 ranking function

```
cd BM25/
g++ -std=c++17 main.cpp -o main && ./main product_names.txt
```

# Evaluation

Hiện tại thời gian trung bình của hàm preprocessing_document nằm ở 20-25s. 

Nguyên nhân là hàm `remove_vietnamese_tone` dùng để loại bỏ dấu tiếng việt chạy chưa được tối ưu. 


## Reversed-index

Mỗi query mất trung bình 1-2s.
Do chỉ liệt kê ra các document có đẩy đủ các token từ keyword nên hàm query chạy khá nhanh. 
Tuy nhiên các kết quả chưa thể hiện Sự liên quan giữa document và keyword. 

## BM25 ranking function

Mỗi query mất trung bình 50-60s do phải tính toán cho mỗi token trong keyword với các document mà nó có mặt. 
Kết quả trả về thể hiện đầy đủ Sự liên quan được tính theo trọng số và cả những kết quả chỉ chứa một phần của keyword. 

