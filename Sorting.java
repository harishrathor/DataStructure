import java.io.*;

class Sorting{

		void Merge(int arr[],int l,int mid,int r){
			int leftLength=mid-l+1;
			int rightLength=r-mid;
			int leftArr[]=new int[leftLength];
			int rightArr[]=new int[rightLength];

			for(int i=0;i<leftLength;i++)
				leftArr[i]=arr[l+i];
			for(int i=0;i<rightLength;i++)
				rightArr[i]=arr[mid+1+i];

			int i=0,j=0,k=l;

			while(i<leftLength && j<rightLength){
				if(leftArr[i]<rightArr[j]){
					arr[k]=leftArr[i];
					i++;
					k++;
				}else{
					arr[k]=rightArr[j];
					j++;
					k++;
				}
			}
			while(i<leftLength){
				arr[k]=leftArr[i];
				i++;k++;
			}
			while(j<rightLength){
				arr[k]=rightArr[j];
				j++;k++;
			}
		}
		int partition(int[] arr1,int l,int r){
			int pIndex=l,t;
			int pivot=arr1[r];
			for(int i=l;i<=r;i++){
				if(pivot>arr1[i]){
					t=arr1[pIndex];
					arr1[pIndex]=arr1[i];
					arr1[i]=t;
					pIndex++;
				}
			}
			t=arr1[pIndex];
			arr1[pIndex]=arr1[r];
			arr1[r]=t;
			return pIndex;
		}
		void MergeSort(int[] arr,int l,int r){
			if(l<r){
					int mid=(l+r)/2;
					this.MergeSort(arr,l,mid);
					this.MergeSort(arr,mid+1,r);
					this.Merge(arr,l,mid,r);
			}
		}
		void QuickSort(int arr1[],int l,int r){
			if(l<r){
					int pIndex=this.partition(arr1,l,r);
					this.QuickSort(arr1,l,pIndex-1);
					this.QuickSort(arr1,pIndex+1,r);
			}
		}
		static void printArr(int[] arr){
			for(int i=0;i<arr.length;i++)
				System.out.print("\t"+arr[i]);
		}
		public static void main(String args[]){
			Sorting s=new Sorting();
			int arr[]={7,1,3,0,8,2,10,4,5};
			int arr1[]={8,1,10,2,11,45,5,22};
			Sorting.printArr(arr);
			s.MergeSort(arr,0,arr.length-1);
			System.out.println("\nSorted Array by MergeSort\n");
			Sorting.printArr(arr);
			System.out.println("\nArray for QuickSort");
			Sorting.printArr(arr1);
			s.QuickSort(arr1,0,arr1.length-1);
			System.out.println("\nSorted Array by QuickSort\n");
			Sorting.printArr(arr1);
		}
}
