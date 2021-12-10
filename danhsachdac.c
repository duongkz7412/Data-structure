#include <stdio.h>
#include <math.h>
#include <string.h>

#define Maxlength 20
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlength];
	int Last;
}List;

#ifndef MaxLength
#define MaxLength 300 // So phan tu toi da
#endif

#ifndef ElementType
    typedef int ElementType; // Kieu du lieu cua phan tu
#endif

#ifndef Position
    typedef int Position; // Position = index + 1
#endif

    typedef struct
    {
        ElementType Elements[MaxLength];
        Position Last;
    } List;
    
    // hàm chép toàn bộ các số chẵn trong danh sách L1 sang danh sách kết quả
    void copyEvenNumbers(List list1, List * pL2)
    {
        pL2->Last = 0;
        for (int i = 0; i < list1.Last; i++)
            if (list1.Elements[i] % 2 == 0)
            {
                pL2->Elements[pL2->Last] = list1.Elements[i];
                pL2->Last++;
            }
    }

    // dem x trong List
    int countList(ElementType x, List list)
    {
        int count = 0;
        for (int i = 0; i < list.Last; i++)
            if (list.Elements[i] == x)
                count++;
        return count;
    }

    // ham xoa mot phan tu tai vi tri p
    void deleteList(Position p, List * pL)
    {
        if (p < first(*pL) || p >= endList(*pL))
        {
            printf("Vi tri khong hop le\n");
            return;
        }

        for (Position i = p; i < pL->Last; i++)
            pL->Elements[i - 1] = pL->Elements[i];

        pL->Last--;
    }

    // tim hieu cua hai tap
    void difference(List list1, List list2, List * pL)
    {
        makenullList(pL);
        for (int i = 0; i < list1.Last; i++)
            if (!member(list1.Elements[i], list2))
                insertSet(list1.Elements[i], pL);
    }

    // ham kiem tra mot ds co rong hay khong
    int emptyList(List list)
    {
        return list.Last == 0;
    }

    // ham tra ve vi tri sau vi tri cuoi cung cua List
    Position endList(List list)
    {
        return list.Last + 1;
    }

    // Xóa phần tử đầu tiên có giá trị là x trong danh sách chỉ bởi con trỏ pL
    void erase(ElementType x, List * pL)
    {
        deleteList(locate(x, *pL), pL);
    }

    // ham kiem tra ham co full khong
    int fullList(List list)
    {
        return list.Last == MaxLength;
    }

    // ham tra ve vi tri dau tien cua List
    Position first(List list)
    {
        return 1;
    }

    // tra ve gia tri trung binh cua List
    float getAvg(List list)
    {
        if (list.Last == 0)
            return -10000;
        return (float)sumList(list) / list.Last;
    }

    // ham chen 1 phan tu vao List
    void insertList(ElementType x, Position p, List * pL)
    {
        if (fullList(*pL))
            return;

        if (p < first(*pL) || p > endList(*pL) + 1)
            return;

        for (Position i = pL->Last; i >= p; i++)
            pL->Elements[i] = pL->Elements[i - 1];

        pL->Elements[p - 1] = x;
        pL->Last++;
    }

    // them phan tu vao cuoi List
    void insertSet(ElementType x, List * pL)
    {
        pL->Elements[pL->Last] = x;
        pL->Last++;
    }

    // ham tim tap giao cua L1 L2
    void intersection(List list1, List list2, List * pL)
    {
        makenullList(pL);
        for (int i = 0; i < list1.Last; i++)
            if (member(list1.Elements[i], list2))
                insertSet(list1.Elements[i], pL);
    }

    // ham tra ve vi tri dau tien cua phan tu x co trong List
    Position locate(ElementType x, List list)
    {
        for (int i = 1; i <= list.Last; i++)
            if (x == retrieve(i, list))
                return i;
        return list.Last + 1;
    }

    //  trả về giá trị nhỏ nhất trong các phần tử của danh sách L
    ElementType minList(List list)
    {
        ElementType min = list.Elements[0];
        for (int i = 0; i < list.Last; i++)
            if (min > list.Elements[i])
                min = list.Elements[i];
        return min;
    }

    // lam rong danh sach
    void makenullList(List * pL)
    {
        pL->Last = 0;
    }

    // ham kiem tra 1 phan tu co trong List hay khong
    int member(ElementType x, List list)
    {
        for (int i = 1; i <= list.Last; i++)
            if (x == retrieve(i, list))
                return 1;
        return 0;
    }

    //  trả về giá trị lớn nhất trong các phần tử của danh sách L
    ElementType maxList(List list)
    {
        ElementType max = list.Elements[0];
        for (int i = 0; i < list.Last; i++)
            if (max < list.Elements[i])
                max = list.Elements[i];
        return max;
    }

    // tra ve vi tri sau vi tri p trong List
    Position next(Position p, List L)
    {
        if (p > L.Last)
            return 0;
        if (p == L.Last)
            return endList(L);
        return p + 1;
    }

    // lam cho List co phan tu duy nhat
    void normalize(List * pL)
    {
        for (int i = 0; i < pL->Last; i++)
            for (int j = i + 1; j < pL->Last; j++)
                if (pL->Elements[i] == pL->Elements[j])
                {
                    deleteList(j + 1, pL);
                    j--;
                }
    }

    // tra ve vi tri truoc vi tri p trong List
    Position previous(Position p, List L)
    {
        if (p <= first(L))
            return 0;
        return p - 1;
    }

    // in ra List
    void printList(List L)
    {
        for (Position p = 1; p <= L.Last; p++)
            printf("%d ", retrieve(p, L));

        printf("\n");
    }

    // ham in so le
    void printOddNumbers(List list)
    {
        for (int i = 0; i < list.Last; i++)
            if (!(list.Elements[i] % 2 == 0))
                printf("%d ", list.Elements[i]);
        printf("\n");
    }

    // ham tra ve gia tri cua List tai vi tri p
    ElementType retrieve(Position p, List list)
    {
        if (!(p > list.Last))
            return list.Elements[p - 1];
        return 0;
    }

    // xoa tat ca phan tu co gia tri x trong List
    void removeAll(ElementType x, List * pL)
    {
        while (member(x, *pL))
            deleteList(locate(x, *pL), pL);
    }

    // ham nhap List tu ban phim
    void readList(List * pL)
    {
        makenullList(pL);
        int n, e;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &e);
            insertList(e, pL->Last + 1, pL);
        }
    }

    // ham them n phan tu vao List neu no chua co trong List
    void readSet(List * pL)
    {
        readList(pL);
        normalize(pL);
    }

    // trả về tổng giá trị các phần tử trong danh sách L
    ElementType sumList(List list)
    {
        ElementType sum = 0;
        for (int i = 0; i < list.Last; i++)
            sum += list.Elements[i];
        return sum;
    }

    // ham hoan doi 2 phan tu trong mang
    void swap(ElementType array[], int i, int j)
    {
        ElementType temp = array[i];

        array[i] = array[j];
        array[j] = temp;
    }

    // ham sap xep
    void sort(List * pL)
    {
        for (int i = 0; i < pL->Last; i++)
            for (int j = i + 1; j < pL->Last; j++)
                if (pL->Elements[i] > pL->Elements[j])
                    swap(pL->Elements, i, j);
    }

    // tap hop cua 2 tap
    void unionSet(List list1, List list2, List * pL)
    {
        makenullList(pL);
        int i;
        for (i = 0; i < list1.Last; i++)
            insertSet(list1.Elements[i], pL);

        for (i = 0; i < list2.Last; i++)
            if (!member(list2.Elements[i], list1))
                insertSet(list2.Elements[i], pL);
    }



    struct SinhVien
    {
        char MSSV[10], HoTen[50];
        float DiemLT, DiemTH1, DiemTH2;
    };

    typedef struct
    {
        SinhVien A[40];
        int n;
    } DanhSach;

    DanhSach dsRong()
    {
        DanhSach D;
        D.n = 0;
        return D;
    }

    void chenCuoi(struct SinhVien S, DanhSach* L)
    {
        L->A[L->n] = S;
        L->n++;
    }

    int tim(char MSSV[10], DanhSach L)
    {
        for (int i = 0; i < L.n; i++)
            if (strcmp(MSSV, L.A[i].MSSV) == 0)
                return i + 1;
        return L.n + 1;
    }

    void xoaTai(int p, DanhSach* L)
    {
        for (int i = p; i < L->n; i++)
            L->A[i - 1] = L->A[i];
        L->n--;
    }

    void hienthi(DanhSach danhSach)
    {
        for (int i = 0; i < danhSach.n; i++)
            printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", danhSach.A[i].MSSV, danhSach.A[i].HoTen, danhSach.A[i].DiemLT, danhSach.A[i].DiemTH1, danhSach.A[i].DiemTH2, danhSach.A[i].DiemLT + danhSach.A[i].DiemTH1 + danhSach.A[i].DiemTH2);
    }

    int length(char* string)
    {
        int i = 0;
        while (string[i])
            i++;
        return i;
    }

    struct SinhVien nhapSV()
    {
        struct SinhVien sinhVien;

        getchar();
        fgets(sinhVien.MSSV, 10, stdin);
        sinhVien.MSSV[length(sinhVien.MSSV) - 1] = '\0';
        fflush(stdin);

        fgets(sinhVien.HoTen, 50, stdin);
        sinhVien.HoTen[length(sinhVien.HoTen) - 1] = '\0';
        fflush(stdin);

        scanf("%f", &sinhVien.DiemLT);
        scanf("%f", &sinhVien.DiemTH1);
        scanf("%f", &sinhVien.DiemTH2);

        return sinhVien;
    }

    DanhSach nhap()
    {
        DanhSach danhSach = dsRong();
        struct SinhVien sinhVien;
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            sinhVien = nhapSV();
            if (tim(sinhVien.MSSV, danhSach) < 1 || tim(sinhVien.MSSV, danhSach) >= danhSach.n)
            {
                chenCuoi(sinhVien, &danhSach);
            }
        }
        return danhSach;
    }

    float tongDiem(struct SinhVien S)
    {
        return S.DiemLT + S.DiemTH1 + S.DiemTH2;
    }

    DanhSach chepKhongDat(DanhSach L)
    {
        DanhSach _L = dsRong();
        for (int i = 0; i < L.n; i++)
            if (tongDiem(L.A[i]) < 4)
                chenCuoi(L.A[i], &_L);
        return _L;
    }

    void xoaSinhVien(char MSSV[10], DanhSach* pL)
    {
        while (tim(MSSV, *pL) <= pL->n)
            xoaTai(tim(MSSV, *pL), pL);
    }
