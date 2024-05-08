#• Si el enunciado lo requiere, deberás entregar un Makefile que compilará tus archivos
#fuente al output requerido con las flags -Wall, -Werror y -Wextra y por supuesto
#tu Makefile no debe hacer relink.
#• Tu Makefile debe contener al menos las normas $(NAME), all, clean, fclean y
#re.
#• Para entregar los bonus de tu proyecto deberás incluir una regla bonus en tu
#Makefile, en la que añadirás todos los headers, librerías o funciones que estén
#prohibidas en la parte principal del proyecto. Los bonus deben estar en archivos
#distintos _bonus.{c/h}. La parte obligatoria y los bonus se evalúan por separado.

get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out