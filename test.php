<?php

// set default count or grab from request var
$count = 1000000000;
if (!empty($_GET["count"])) {
    $count = intval($_GET["count"]);
}

// one print statement to start, followed by what our count actually is
echo "<!doctype html><html><head><title>test</title></head><body><pre>\n\n";
echo "$count\n";

// we'll use this to keep track of how many printed periods we have
$print_count = 0;

// lets do some loops!
for ($i = 0; $i < $count; $i++) {
    for ($j = 0; $j < $count; $j++) {
        for ($k = 0; $k < $count; $k++) {

            // we want this outside of the check
            $print_count++;

            // if we have `print` request var set, then print a period
            // for each loop, and after every 96 printed, then
            // print a newline (95 are actually printed because of the way
            // the print_count is added and whatnot. doesn't matter. let it go)
            if (!empty($_GET["print"])) {
                echo ".";

                if ($print_count >= 96) {
                    echo "\n";
                    $print_count = 0;
                }
            }
        }
    }
}

// one print statement to end
echo "\n\n</pre></html>\n";
