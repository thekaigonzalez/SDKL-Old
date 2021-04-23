package SDKLTypeError;
use strict;
use Error;
use warnings FATAL => 'all';





my $error;


$error = Error->new;


sub new {
    return $error->throw()
}