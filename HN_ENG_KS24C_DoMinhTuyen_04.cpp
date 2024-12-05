#include<stdio.h>
int main (){
	int i, n=0, j, choice, value, position, element, target, temp; 
	int arr[100]; 
	do{
		printf("\n MENU\n");
		printf("1. Nhap so phan tu va gia tri cho mang.\n");
		printf("2. In ra cac gia tri phan tu trong mang.\n");
		printf("3. Dem so luong cac so hoan hao co trong mang.\n");
		printf("4. Tim gia tri lon thu hai trong mang.\n");
		printf("5. Them mot phan tu vao vi tri ngau nhien trong mang.\n");
		printf("6. Xoa phan tu tai mot vi tri cu the.\n");
		printf("7. Sap xep mang theo thu tu tang dan.\n");
		printf("8. Tim kiem phan tu.\n");
		printf("9. Sap xep lai mang va hien thi toan bo phan tu co trong mang(so chan dung truoc, so le dung sau).\n");
		printf("10. Dao nguoc ca phan tu co trong mang.\n");
		printf("11. Thoat.\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		if(choice==1){
			printf("Moi nhap so phan tu cua mang: ");
			scanf("%d", &n);
			for(i=0;i<n;i++){
				printf("Moi nhap phan tu thu %d cua mang: ", i+1);
				scanf("%d", &arr[i]);
			} 
		}else if(choice==2){
			if(n==0){
				printf("Mang rong"); 
			}else{ 
				printf("Cac phan tu trong mang la: ");
				for(i=0;i<n;i++){
					printf(" %d ", arr[i]);
				}
			}
		}else if(choice==3){
			
		}else if(choice==4){
			
		}else if(choice==5){
			if(n==0){
				printf("Mang rong"); 
			}else{ 
				do {
			        printf("\nMoi nhap vi tri can them (1 -> %d): ", n + 1);
			        scanf("%d", &position);
			    } while (position<1 || position>n+1);
				    printf("Moi nhap gia tri can them: ");
				    scanf("%d", &value);
				    for (i=n;i>=position;i--){
				        arr[i] = arr[i - 1];
				    }
				    arr[position-1]=value;
				    n++;
			}
		}else if(choice==6){
			if(n==0){
				printf("Mang rong"); 
			}else{
				do{
	    			printf("\nMoi nhap vi tri can xoa: ");
	    			scanf("%d", &position);
				}while(position<1 || position>n);
				for(i=position-1;i<n-1;i++){
	    		arr[i]=arr[i+1];
				}
				n--;
			}
		}else if(choice==7){
			if(n==0){
				printf("Mang rong"); 
			}else{
				for(i=1;i<n;i++){
	        		element=arr[i];
	        		j=i-1;
	        		while(j>=0&&arr[j]>element){
	            		arr[j+1]=arr[j];
	            		j--;
	        		}
	        	arr[j+1]=element;
	    		}
	    		printf("\nmang sap xep theo thu tu tang dan la: \n");
	    		for(i=0;i<n;i++){
	        		printf(" %d ", arr[i]);
	    		}
	    	}
		}else if(choice==8){
			if(n==0){
				printf("Mang rong"); 
			}else{
				for (i = 0; i < n - 1; i++) {
			        for (j = 0; j < n - 1 - i; j++) {
			            if (arr[j] > arr[j + 1]) {
			                temp = arr[j];
			                arr[j] = arr[j + 1];
			                arr[j + 1] = temp;
			            }
			        }
				}
				printf("mang sau khi sap xep la: ");
				for(i=0;i<n;i++){
					printf("%d\t", arr[i]); 
				} 
			    printf("Moi nhap phan tu can tim: ");
			    scanf("%d", &target);
				for (int i=0;i<n;i++){
					if(arr[i]==target){
						value+=1;
						position=i;
					}
				}
				if(value==1){	
				printf("Phan tu %d da duoc tim thay tai vi tri %d.\n", target, position+1);
				} else{
				printf("Phan tu %d khong ton tai trong mang.\n", target);
			    }
			}
		}else if(choice==9){
			
		}else if(choice==10){
			if(n==0){
				printf("Mang rong"); 
			}else{
				j=n-1; 
				for(i=0;i<n/2;i++){
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
					--j; 
				} 
				for(i=0;i<n;i++){
					printf(" %d ", arr[i]); 
				}
			}
		}else if(choice==11){
			printf("Thoat.\n");
		}else{
			printf("Lua chon khong hop le."); 
		} 
	}while(choice!=11); 
	return 0; 
}
