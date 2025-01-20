/**
 * Author: neko-nyaa
 * Date: 2019-12-28
 * Source: CF940F
 * Description: Let a query be $(T, L, R)$ where $T$ is the number of updates performed. Sort
 * queries by $(T/blk, L/blk, R)$ where $blk = N^{2/3}$ (approx ~ 3500), then run Mo by
 * rolling back updates.
 * Time: $O(N^{5/3})$
 */
