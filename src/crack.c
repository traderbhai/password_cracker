#define _GNU_SOURCE
#include <crypt.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread(void* arg) {
	return NULL;
}

int main(int argc, char** argv) {
	if (argc == 4) {
		// initialisation des variables
		char* hash = argv[1];
		char* salt = argv[2];
		int threads_nb = atoi(argv[3]);

		// test de la fonction crypt_r
		struct crypt_data* cdata = (struct crypt_data *)malloc(sizeof(struct crypt_data));
		cdata->initialized = 0;
		char* my_hash = crypt_r("Steven aime sucer", salt, cdata);
		printf("%s\n",my_hash);

		// initialisation des threads
		pthread_t t[threads_nb];
		for (int i = 0; i < threads_nb; i++) {
			if (pthread_create(&t[i], NULL, thread, NULL) != 0) {
				fprintf(stderr, "pthread_create failed!\n");
				return EXIT_FAILURE;
			}
		}
		for (int i = 0; i < threads_nb; i++) {
			if (pthread_join(t[i], NULL) != 0) {
				fprintf(stderr, "pthread_join failed!\n");
				return EXIT_FAILURE;
			}
		}
		free(cdata);
		return EXIT_SUCCESS;
	} else {
		fprintf(stderr,"Invalid argument count !\n");
		return EXIT_FAILURE;
	}
}
