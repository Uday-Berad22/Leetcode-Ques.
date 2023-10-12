/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int low=-1;
        int high=n+1;
        int index=-1;
        while(high-low>1){
            int mid=(high+low)/2;
            if(mid>=n||mid<0) return -1;
            int x=mountainArr.get(mid);
            int y=INT_MIN,z=INT_MIN;
            if(mid+1<n)
            y=mountainArr.get(mid+1);
            if(mid-1>=0)
            z=mountainArr.get(mid-1);
            if(x>y&&x>z){
                index=mid;
                break;
            }
            else if(x<y){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        high=index+1;
        low=-1;
        while(high-low>1){
            int mid=(high+low)/2;
            if(mid>=n||mid<0) return -1;
            int x=mountainArr.get(mid);
            if(x==target){
                return mid;
            }
            else if(x<target){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        high=n+1;
        low=index;
        while(high-low>1){
            int mid=(high+low)/2;
            if(mid>=n||mid<0) return -1;
            int x=mountainArr.get(mid);
            if(x==target){
                return mid;
            }
            else if(x>target){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        return -1;
    }
};