
/*
divide values into buckets, each representing a range of values
sort each bucket separately then merge the buckets

best case: o(n+k)
medium case: o(n+k)
worst case: o(n²)

very efficient when the data is evenly distributed
each bucket tends to contain a few elements

strongly dpends on data stribution
if many elements fall into the same bucket, performance gets worse
*/
