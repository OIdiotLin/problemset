#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
 
using namespace std ;
 
#define MAXN 110
#define MAXM 2010
#define eps 1e-9
#define inf 0x7fffffff
#define AddEdge( s , t , f ) Add( s , t , f ) ,Add( t , s , 0 ) 
 
struct edge {
    int t , next ;
    double f ;
} node[ MAXM ] ;
 
int head[ MAXN ] , V = 0 , n , e[ MAXM ][ 2 ] , m ;
double ef[ MAXM ] , P ;
 
void Add( int s , int t , double f ) {
    node[ V ].t = t , node[ V ].f = f ;
    node[ V ].next = head[ s ] ;
    head[ s ] = V ++ ;
}
 
int d[ MAXN ] , h[ MAXN ] , gap[ MAXN ] ;
 
void rebuild( double Min ) {
    for ( int i = 0 ; i ++ < n ; ) head[ i ] = - 1 ;
    V = 0 ;
    for ( int i = 0 ; i ++ < m ; )AddEdge( e[ i ][ 0 ] , e[ i ][ 1 ] ,min( ef[ i ] , Min ) ) ;
}
 
double sap( int v , double flow ) {
    if ( v == n ) return flow ;
    double rec = 0 ;
    for ( int p = d[ v ] ; p != -1 ; p = node[ p ].next ) if ( node[ p ].f > eps && h[ v ] == h[ node[ p ].t ] + 1 ) {
        double ret =sap( node[ p ].t ,min( flow - rec , node[ p ].f ) ) ;
        node[ p ].f -= ret , node[ p ^ 1 ].f += ret , d[ v ] = p ;
        rec += ret ;
        if ( flow - rec < eps ) return flow ;
    }
    if ( ! gap[ h[ v ] ] ) h[ 1 ] = n ;
    gap[ ++ h[ v ] ] ++ , d[ v ] = head[ v ] ;
    return rec ;
}
 
double maxflow( double Min ) {
    rebuild( Min ) ;
    double flow = 0 ;
    memset( gap , 0 , sizeof( gap ) ) ;
    memset( h , 0 , sizeof( h ) ) ;
    for ( int i = 0 ; i ++ < n ; ) d[ i ] = head[ i ] ;
    gap[ 0 ] = n ;
    while ( h[ 1 ] < n ) flow +=sap( 1 , inf ) ;
    return flow ;
}
 
int main(  ) {
    scanf( "%d%d%lf" , &n , &m , &P ) ;
    double l , r = 0 ;
    for ( int i = 0 ; i ++ < m ; ) {
        scanf( "%d%d%lf" , &e[ i ][ 0 ] , &e[ i ][ 1 ] , &ef[ i ] ) ;
        r =max( r , ef[ i ] ) ;
    }
    double flow =maxflow( r ) ;
    while ( r - l > eps ) {
        double mid = ( l + r ) / 2 ;
        double rec =maxflow( mid ) ;
        if ( flow - rec > eps ) l = mid ; else r = mid ;
    }
    printf( "%.0f\n%.5f\n" , flow , P * r ) ;
    return 0 ;
}
