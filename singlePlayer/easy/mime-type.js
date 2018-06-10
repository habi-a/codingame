var mimeTable = [];
var N = parseInt(readline()); // Number of elements which make up the association table.
var Q = parseInt(readline()); // Number Q of file names to be analyzed.

for (var i = 0; i < N; i++) {
    var inputs = readline().split(' ');
    var EXT = inputs[0]; // file extension
    var MT = inputs[1]; // MIME type.
    if (EXT.length <= 10 && MT.length <= 50)
    {
	EXT = EXT.toLowerCase(EXT);
	mimeTable[EXT] = MT;
    }
}

printErr('\n');

for (var i = 0; i < Q; i++) {
    var FNAME = readline(); // One file name per line.
    var res = FNAME.split(/\.(.+)/)[1];
    if (res)
    {
	res = res.match(/\w+(.)?$/);
	if (res)
	{
	    res = res[0];
	    res = res.toLowerCase(res);
	}
    }
    if (res && typeof mimeTable[res] !== 'undefined' && mimeTable[res] !== null)
	print(mimeTable[res]);
    else
	print("UNKNOWN");

}
