---
title: JPEG Compression Algorithm Implementation
author: Logan Jackson
date: \today{}
---

## Background and JPEG
The original article defining the JPEG compression standard was released in the
ACM in 1991 although a revised paper was published in 1992 in the journal IEEE
transactions on consumer electronics this implementation is largely based off
that paper, additional sources will be cited etc. etc.

## RAW Images
There's a number of raw image formats that I could use although the best one at
the moment to be using it seems is the DNG format I could also implement TIFF as
it seems fairly common as well and DNG is built upon TIFF but TIFF is also
really old like from 1992 so not sure maybe I'll do support for both I wouldn't
expect full support though because these are entire books for the specification
which is a little much not looking to implement absolutely everything right now
just looking to write a JPEG compression algorithm for fun!

## Parts
Essentially the project at this point is 2 parts first deserializing DNG then
second which is the JPEG compression algorithm I think for the most part I will
ignore DNG deserialization for and focus on JPEG compression since I could just
use a library or something like that at the end of the day even if I wouldn't
want to

