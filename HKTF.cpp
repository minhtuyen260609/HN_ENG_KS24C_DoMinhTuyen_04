#include <stdio.h>
int main() {
    int arr[100];
    int n = 0, choice, i, j, temp;
    do {
        printf("\n\tMENU\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang (arr[0]=..., arr[1]=...)\n");
        printf("3. Dem so luong hoan hao\n");
        printf("4. Dem so luong nguyen to\n");
        printf("5. Tim gia tri lon thu 2 (Khong sap xep)\n");
        printf("6. Tim gia tri nho thu 2 (Khong sap xep)\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan (sap xep chen)\n");
        printf("10. Sap xep mang giam dan (sap xep chen)\n");
        printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Sap xep va hien thi so le dung truoc, so chan dung sau\n");
        printf("15. Dao nguoc mang\n");
        printf("16. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // Nhap so luong va gia tri cho cac phan tu
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                if (n > 100 || n <= 0) {
                    printf("So phan tu khong hop le.\n");
                } else {
                    for (i = 0; i < n; i++) {
                        printf("Nhap gia tri cho arr[%d]: ", i);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            case 2: // In mang
                printf("Mang hien tai: ");
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d ", i, arr[i]);
                }
                printf("\n");
                break;
            case 3: // Dem so luong hoan hao
                {
                    int countPerfect = 0;
                    for (i = 0; i < n; i++) {
                        int sum = 0;
                        for (j = 1; j < arr[i]; j++) {
                            if (arr[i] % j == 0) {
                                sum += j;
                            }
                        }
                        if (sum == arr[i]) {
                            countPerfect++;
                        }
                    }
                    printf("So luong so hoan hao trong mang: %d\n", countPerfect);
                }
                break;
            case 4: // Dem so luong nguyen to
                {
                    int countPrime = 0;
                    for (i = 0; i < n; i++) {
                        int isPrime = 1;
                        if (arr[i] < 2) {
                            isPrime = 0;
                        }
                        for (j = 2; j * j <= arr[i]; j++) {
                            if (arr[i] % j == 0) {
                                isPrime = 0;
                                break;
                            }
                        }
                        if (isPrime) {
                            countPrime++;
                        }
                    }
                    printf("So luong so nguyen to trong mang: %d\n", countPrime);
                }
                break;
            case 5: // Tim gia tri lon thu 2
                {
                    if (n < 2) {
                        printf("Mang khong du 2 phan tu.\n");
                    } else {
                        int max1 = arr[0], max2 = arr[1];
                        if (max1 < max2) {
                            max1 = arr[1];
                            max2 = arr[0];
                        }
                        for (i = 2; i < n; i++) {
                            if (arr[i] > max1) {
                                max2 = max1;
                                max1 = arr[i];
                            } else if (arr[i] > max2) {
                                max2 = arr[i];
                            }
                        }
                        printf("Gia tri lon thu 2: %d\n", max2);
                    }
                }
                break;
            case 6: // Tim gia tri nho thu 2
                {
                    if (n < 2) {
                        printf("Mang khong du 2 phan tu.\n");
                    } else {
                        int min1 = arr[0], min2 = arr[1];
                        if (min1 > min2) {
                            min1 = arr[1];
                            min2 = arr[0];
                        }
                        for (i = 2; i < n; i++) {
                            if (arr[i] < min1) {
                                min2 = min1;
                                min1 = arr[i];
                            } else if (arr[i] < min2) {
                                min2 = arr[i];
                            }
                        }
                        printf("Gia tri nho thu 2: %d\n", min2);
                    }
                }
                break;
            case 7: // Them phan tu tai vi tri
                {
                    int position, value;
                    printf("Nhap vi tri (0 den %d) va gia tri phan tu: ", n);
                    scanf("%d %d", &position, &value);
                    if (position < 0 || position > n) {
                        printf("Vi tri khong hop le.\n");
                    } else {
                        for (i = n; i > position; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[position] = value;
                        n++;
                        printf("Mang sau khi them: ");
                        for (i = 0; i < n; i++) {
                            printf("arr[%d] = %d ", i, arr[i]);
                        }
                        printf("\n");
                    }
                }
                break;
            case 8: // Xoa phan tu tai vi tri
                {
                    int delPos;
                    printf("Nhap vi tri (0 den %d) cua phan tu can xoa: ", n - 1);
                    scanf("%d", &delPos);

                    if (delPos < 0 || delPos >= n) {
                        printf("Vi tri khong hop le.\n");
                    } else {
                        for (i = delPos; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                        printf("Mang sau khi xoa: ");
                        for (i = 0; i < n; i++) {
                            printf("arr[%d] = %d ", i, arr[i]);
                        }
                        printf("\n");
                    }
                }
                break;
	    case 9: // Sap xep mang tang dan (sap xep chen)
                for (i = 1; i < n; i++) {
                    temp = arr[i];
                    j = i - 1;
                    while (j >= 0 && arr[j] > temp) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = temp;
                }
                printf("Mang sau khi sap xep tang dan: ");
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d ", i, arr[i]);
                }
                printf("\n");
                break;
            case 10: // Sap xep mang giam dan (sap xep chen)
                for (i = 1; i < n; i++) {
                    temp = arr[i];
                    j = i - 1;
                    while (j >= 0 && arr[j] < temp) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = temp;
                }
                printf("Mang sau khi sap xep giam dan: ");
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d ", i, arr[i]);
                }
                printf("\n");
                break;
            case 11: // Tim kiem phan tu (Tim kiem nhi phan)
                {
                    int key, low = 0, high = n - 1, mid, found = 0;
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &key);                                      
                    for (i = 1; i < n; i++) {
                        temp = arr[i];
                        j = i - 1;
                        while (j >= 0 && arr[j] > temp) {
                            arr[j + 1] = arr[j];
                            j--;
                        }
                        arr[j + 1] = temp;
                    }
                    while (low <= high) {
                        mid = (low + high) / 2;
                        if (arr[mid] == key) {
                            found = 1;
                            break;
                        } else if (arr[mid] < key) {
                            low = mid + 1;
                        } else {
                            high = mid - 1;
                        }
                    }
                    if (found) {
                        printf("Phan tu %d da duoc tim thay tai vi tri %d.\n", key, mid);
                    } else {
                        printf("Phan tu %d khong ton tai trong mang.\n", key);
                    }
                }
                break;
            case 13: // Sap xep va hien thi so chan dung truoc, so le dung sau
                {
                    int even[100], odd[100];
                    int evenCount = 0, oddCount = 0;

                    for (i = 0; i < n; i++) {
                        if (arr[i] % 2 == 0) {
                            even[evenCount++] = arr[i];
                        } else {
                            odd[oddCount++] = arr[i];
                        }
                    }
                    printf("So chan: ");
                    for (i = 0; i < evenCount; i++) {
                        printf("%d ", even[i]);
                    }
                    printf("\n");

                    printf("So le: ");
                    for (i = 0; i < oddCount; i++) {
                        printf("%d ", odd[i]);
                    }
                    printf("\n");
                }
                break;
            case 14: // Sap xep va hien thi so le dng truoc, so chan dung sau
                {
                    int even[100], odd[100];
                    int evenCount = 0, oddCount = 0;
                    for (i = 0; i < n; i++) {
                        if (arr[i] % 2 != 0) {
                            odd[oddCount++] = arr[i];
                        } else {
                            even[evenCount++] = arr[i];
                        }
                    }
                    printf("So le: ");
                    for (i = 0; i < oddCount; i++) {
                        printf("%d ", odd[i]);
                    }
                    printf("\n");

                    printf("So chan: ");
                    for (i = 0; i < evenCount; i++) {
                        printf("%d ", even[i]);
                    }
                    printf("\n");
                }
                break;
            case 15: // Dao nguoc mang
                {
                    int startIndex = 0;
                    for (i = n - 1; i >= 0; i--) {
                        arr[startIndex++] = arr[i];
                    }
                    printf("Mang sau khi dao nguoc: ");
                    for (i = 0; i < n; i++) {
                        printf("arr[%d] = %d ", i, arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 16: // Thoat
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 16);
    return 0;
}
