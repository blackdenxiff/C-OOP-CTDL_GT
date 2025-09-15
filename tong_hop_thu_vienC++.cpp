| Nhóm                   | Tên thư viện         | Công dụng chính                   |
| ---------------------- | -------------------- | --------------------------------- |
| **Nhập/xuất**          | `<iostream>`         | Nhập xuất chuẩn (cin, cout)       |
|                        | `<fstream>`          | Nhập xuất file                    |
| **Xử lý chuỗi**        | `<string>`           | Chuỗi (std::string)               |
| **Toán học**           | `<cmath>`            | Hàm toán học (sqrt, sin, pow\...) |
|                        | `<cstdlib>`          | Random, exit(), atoi()...         |
| **Dữ liệu**            | `<vector>`           | Mảng động                         |
|                        | `<array>`            | Mảng tĩnh C++                     |
|                        | `<list>`             | Danh sách liên kết đôi            |
|                        | `<deque>`            | Hàng đợi 2 đầu                    |
|                        | `<queue>`            | Hàng đợi                          |
|                        | `<stack>`            | Ngăn xếp                          |
|                        | `<map>`              | Bản đồ (key-value, tự sắp xếp)    |
|                        | `<unordered_map>`    | Hash map                          |
|                        | `<set>`              | Tập hợp, tự sắp xếp               |
|                        | `<unordered_set>`    | Tập hợp không sắp xếp             |
| **Thuật toán**         | `<algorithm>`        | sort, find, count...              |
|                        | `<numeric>`          | Tính tổng, tích, v.v.             |
| **Thời gian**          | `<chrono>`           | Thời gian, đồng hồ                |
|                        | `<ctime>`            | Thời gian kiểu C                  |
| **Ký tự**              | `<cctype>`           | isalpha, isdigit...               |
| **Con trỏ thông minh** | `<memory>`           | unique\_ptr, shared\_ptr          |
| **Xử lý lỗi**          | `<stdexcept>`        | Ngoại lệ (exception)              |
| **Luồng**              | `<thread>`           | Lập trình đa luồng                |
|                        | `<mutex>`            | Khóa (mutex)                      |
| **Hệ thống & IO thấp** | `<cstdio>`           | Nhập/xuất kiểu C                  |
|                        | `<cstdint>`          | Kiểu số nguyên chính xác          |
|                        | `<bitset>`           | Mảng bit                          |
|                        | `<functional>`       | std::function, lambda             |
|                        | `<utility>`          | std::pair, std::move, std::swap   |
|                        | `<typeinfo>`         | Thông tin kiểu                    |
|                        | `<initializer_list>` | Khởi tạo danh sách                |


<iostream>{

}

<vector>{
1. Vector Và Khai Báo Vector:
   - Vector là một container có tính chất tương tự như 1 mảng động, nó tự thay đổi kích thước khi bạn thêm hay xóa các phần tử trong mảng.
   - Ngoài ra nó hỗ trợ truy cập các phần tử trong mảng thông qua chỉ số như mảng 1 chiều.
   - Vector có thể lưu các kiểu dữ liệu như int, long long, float, char, pair, hoặc thậm chí là một vector khác. Khi sử dụng vector bạn cần thêm thư viện "vector" vào chương trình của mình.

   *Cú pháp khai báo vector :
       vector<data_type> vector_name;
    VD:{
        #include <iostream>
        #include <vector>

        using namespace std;

        int main(){
            //Khai báo vector rỗng
            vector<int> v1;
            //Khai báo vector với các phần tử
            vector<int> v2 = {1, 2, 3, 4, 5};
            //Khai báo vector có sẵn n phần tử
            int n = 20;
            vector<int> v3(n);
            //Khai báo vector có sẵn n phần tử có cùng giá trị val
            int val = 0;
            vector<int> v4(n, val);
            return 0;
        }
    }


2. Hàm size(), length(), push_back() và pop_back();
    size() : Trả về số lượng phần tử trong vector. Độ phức tạp O(1)
    length() : Trả về số lượng phần tử trong vector. Độ phức tạp O(1)
    push_back() : Thêm phần tử vào cuối vector. Độ phức tạp O(1)
    pop_back() : Xóa phần tử cuối cùng trong vector. Độ phức tạp O(1)
    Để duyệt vector bạn có thể duyệt thông qua chỉ số, dùng ranged-base for loop.

    VD:{
        #include <iostream>
        #include <vector>

        using namespace std;

        int main(){
            vector<int> v;
            v.push_back(1); // {1}
            v.push_back(2); // {1, 2}
            v.push_back(3); // {1, 2, 3}
            v.push_back(4); // {1, 2, 3, 4}
            cout << "Kich thuoc vector : " << v.size() << endl; // v.length()
            cout << "Duyet vector bang chi so : \n";
            for(int i = 0; i < v.size(); i++){
                cout << v[i] << ' ';
            }
            cout << "\nDuyet vector bang ranged-base for loop :\n";
            for(int x : v){
                cout << x << ' ';
            }
            return 0;
        }
    }

    Ví dụ 2 : Vector string {

        #include <iostream>
        #include <vector>

        using namespace std;

        int main(){
            vector<string> v = {"28tech", "STL"};
            cout << "Kich thuoc vector : " << v.size() << endl;
            v.push_back("C++");
            v.push_back("Java");
            v.push_back("PHP");
            cout << "Kich thuoc vector : " << v.size() << endl;
            cout << "Duyet vector : ";
            for(int i = 0; i < v.size(); i++){
                cout << v[i] << " ";
            }
            v.pop_back(); // Xoa PHP
            cout << "\nKich thuoc vector : " << v.size() << endl;
        }
        Output :

        Kich thuoc vector : 2
        Kich thuoc vector : 5
        Duyet vector : 28tech STL C++ Java PHP
        Kich thuoc vector : 4 }
3. Vector Và Mảng 1 Chiều

- Tất cả các bài toán sử dụng mảng 1 chiều bạn đều có thể sử dụng vector để thay thế, dưới đây mình sẽ hướng dẫn cách bạn nhập mảng 1 chiều từ bàn phím sử dụng vector.

    Cách 1 :{

    Khai báo vector rỗng và thêm phần tử được nhập từ bàn phím vào cuối vector

    #include <iostream>
    #include <vector>

    using namespace std;

    int main(){
        vector<int> v;
        int n, tmp; cout << "Nhap so luong phan tu : ";
        cin >> n;
        for(int i = 0; i < n; i++){
            cout << "Nhap phan tu thu " << i + 1 << " : ";
            cin >> tmp;
            v.push_back(tmp);
        }
        cout << "Day so vua nhap : \n";
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        return 0;
    }}
    Cách 2 :{

    Khai báo vector có sẵn số lượng phần tử được nhập từ bàn phím

    #include <iostream>
    #include <vector>

    using namespace std;

    int main(){
        int n, tmp; cout << "Nhap so luong phan tu : ";
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cout << "Nhap phan tu thu " << i + 1 << " : ";
            cin >> v[i];
        }
        cout << "Day so vua nhap : \n";
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        return 0;
    }}
4. Vector Và Mảng 2 Chiều

- Mỗi vector có thể sử dụng như mảng 1 chiều, nếu muốn sử dụng vector như mảng 2 chiều bạn cần sử dụng vector các vector.

- Mình sẽ hướng dẫn các bạn 2 cách để lưu mảng 2 chiều vào vector và bạn có thể lựa chọn cách mà mình thấy dễ tiếp cận hơn.

Cách 1 :

Nhập từng dòng của mảng 2 chiều như 1 vector và thêm vào vector chính.

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cout << "Nhap hang, cot : ";
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < m; j++){
            cout << "Nhap phan tu hang " << i + 1 << ", cot " << j + 1 << " : ";
            int tmp; cin >> tmp;
            row.push_back(tmp);
        }
        v.push_back(row);
    }
    cout << "\nMang 2 chieu vua nhap : \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
    Cách 2 :{

    Khai báo sẵn vector có kích thước với hàng, cột được nhập từ bàn phím

    #include <iostream>
    #include <vector>

    using namespace std;

    int main(){
        int n, m;
        cout << "Nhap hang, cot : ";
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << "Nhap phan tu hang " << i + 1 << ", cot " << j + 1 << " : ";
                cin >> v[i][j];
            }
        }
        cout << "\nMang 2 chieu vua nhap : \n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        return 0;}}


 -> xóa pt trong vector{
    Để xóa một mảng (hay chính xác hơn là một phần tử bất kỳ) trong vector C++, bạn dùng phương thức erase() của std::vector.

    Giả sử bạn có một vector chứa các vector<int> (mảng con), và bạn muốn xóa một mảng con ở vị trí bất kỳ, ví dụ vị trí i, thì bạn làm như sau:

    Ví dụ:
    cpp
    Sao chép
    Chỉnh sửa
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<int>> ds = {
            {1, 2, 3},
            {4, 5},
            {6, 7, 8, 9}
        };

        int i = 1; // vị trí muốn xóa (ở đây là mảng {4,5})

        if(i >= 0 && i < ds.size()) {
            ds.erase(ds.begin() + i); // xóa mảng thứ i
        }

        // In lại danh sách sau khi xóa
        for(const auto& v : ds) {
            for(int x : v) cout << x << " ";
            cout << endl;
        }

        return 0;
    }
    Giải thích:
    ds.erase(ds.begin() + i);: Xóa phần tử (là 1 vector) tại chỉ số i.

    ds.begin() là iterator trỏ đến phần tử đầu.

    Bạn cộng i vào để trỏ đúng phần tử cần xóa.

    Nếu bạn dùng vector một chiều như vector<int> và muốn xóa phần tử tại vị trí bất kỳ thì cách làm tương tự:

    cpp
    Sao chép
    Chỉnh sửa
    vector<int> a = {10, 20, 30, 40};
    int i = 2; // muốn xóa phần tử thứ 3 (30)
    if(i >= 0 && i < a.size()) {
        a.erase(a.begin() + i);
    }
 }
}

random{
#include <iostream>
#include <random>

int main() {
    std::random_device rd;                // nguồn ngẫu nhiên từ phần cứng (nếu có)
    std::mt19937 gen(rd());               // tạo máy sinh số ngẫu nhiên với seed
    std::uniform_int_distribution<> dis(1, 5); // sinh số nguyên từ 1 đến 5

    int so = dis(gen); // lấy số ngẫu nhiên
    std::cout << "So ngau nhien tu 1 den 5: " << so << std::endl;
    return 0;
}

//

#include <iostream>
#include <cstdlib>
#include <ctime>

int random1to5() {
    return rand() % 5 + 1;
}

int main() {
    srand(time(0));
    std::cout << "Random: " << random1to5() << std::endl;
    return 0;
}


//
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

int main() {
    srand(time(0)); // Khởi tạo seed cho rand(), chỉ cần gọi 1 lần
    int so = rand() % 100 + 1; // random từ 1 đến 100
    std::cout << "So ngau nhien: " << so << std::endl;
    return 0;
}

}

