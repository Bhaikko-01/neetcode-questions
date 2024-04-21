
/**
 * KRUSKAL
 * Krushkal algo is used to find MST of a Weighted graph - O(ElogE) + O(E) ~ O(ElogE) [T], O(V + E) [S]
 *  Sort the edges based on increasing weights - O(ElogE)
 *  Pick the edge and check if it creates cycle using Union Find algo - O(1)
 *    If cycle created, cannot be picked
 *    Else use that Edge in MST
 *  Pick edges till (n - 1) edges picked - O(E)
 *
 * PRIMS
 * Prims algo picks the min connected edge always based on current nodes. - O(ElogE)
 *  At each step, tree is maintained while creating MST
*/

// For code, refer min-cost-connect-all-points.cpp
