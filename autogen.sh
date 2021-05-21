#! /bin/bash
echo "--- Start autotools -------------"

aclocal \
&& autoheader \
&& automake --add-missing \
&& autoconf

echo "--- Finished autotools ----------"

exit 0