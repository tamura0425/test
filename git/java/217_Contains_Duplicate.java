class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set set = new HashSet(); //重複確認用
        
        for(int duplicateCheck : nums) {
            if(!set.add(duplicateCheck)) {
                //System.out.println(duplicateCheck);
                return  true;
            }
        }
        return  false;
    }
}
