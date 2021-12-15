import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

class Solution {
    void function(int[] nums,List<Integer> d,List<List<Integer>> ans,int temp){
        if(d.size()==3){
            ans.add(d);
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]==-100){
                continue;
            }
            else{
                d.add(nums[i]);
                temp=nums[i];
                nums[i]=-100;
                function(nums,d,ans,temp);
                nums[i]=temp;
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> d = new LinkedList();
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        function(nums,d,ans,0);
        return ans;
    }
}

public class demo{
    public static void main(String[] args) {
        Solution S = new Solution();
        List<List<Integer>> turuans = new ArrayList<List<Integer>>();
        turuans = S.permute(new int[]{1,2,3});
        for(List<Integer> i:turuans){
            for(Integer k:i){
                System.out.print(k + " ");
            }
            System.out.println();
        }
    }
}