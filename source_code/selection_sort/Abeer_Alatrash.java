public class SelectionSortPlay {

    public static void main (String [] args){
        //random array(values between 0 to 100) with random length between 0 to 100
        int [] arr = randArr(100);
        selectionSort(arr);
        //up
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }

        System.out.println(" ");
        //down
        for(int i=(arr.length-1);i>=0;i--){
            System.out.print(arr[i]+" "); }
    }

    private static int[] randArr(int j) {
        int len = (int)(Math.random()*j/1);
        int [] arr=new int [len];
        for(int i = 0;i < len; i++){
            arr[i] = (int)(Math.random()*j/1);
        }
        return arr;
    }

    private static void selectionSort(int[] arr) {
        int indexOfMin;
        for(int i=0;i<arr.length;i++){
            indexOfMin=findMin(arr,i);
            swap(arr,indexOfMin,i);
        }
    }

    private static int findMin(int [] arr,int i) {
        int indexOfMin=i;
        int tmpMin=arr[i];
        for( int j=i; j < arr.length; j++){
            if(tmpMin > arr[j]){
                tmpMin = arr[j];
                indexOfMin = j;
            }
        }
        return indexOfMin;
    }

    private static void swap(int[] arr, int indexOfMin, int j) {
        int tmp=arr[indexOfMin];
        arr[indexOfMin]=arr[j];
        arr[j]=tmp;
    }
}
