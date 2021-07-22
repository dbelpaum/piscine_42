#!/bin/sh
nbr1=`echo $FT_NBR2 | sed 'y/mrdoc/01234/'`
nbr2=`echo $FT_NBR1 | sed 'y/'\''\\"?!/01234/'`
sommeb13=`echo "obase=13;ibase=5;$nbr1+$nbr2" | bc`
echo $sommeb13 | sed 'y/0123456789ABC/gtaio luSnemf/'
