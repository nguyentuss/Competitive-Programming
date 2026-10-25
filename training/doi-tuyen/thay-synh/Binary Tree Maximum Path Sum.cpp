function maxPathSum(root: TreeNode | null): number {
  let result = -Infinity;

  function dfs(root: TreeNode | null) {
    if (root === null) {
      return 0;
    }

    let maxLeft = dfs(root.left);
    let maxRight = dfs(root.right);

    let currentMax = root.val + maxLeft + maxRight;
    result = Math.max(result, currentMax);

    return Math.max(root.val + maxLeft, root.val + maxRight, 0);    
  }

  dfs(root);
    
  return result;
}
