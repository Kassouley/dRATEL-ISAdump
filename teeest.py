import threading
import time

class ThreadManager:
    def __init__(self, num_threads):
        self.barrier = threading.Barrier(num_threads)
        self.results = []
        self.results_lock = threading.Lock()

    def add_result(self, result):
        with self.results_lock:
            self.results.append(result)

    def worker(self, thread_id):
        print(f"Thread {thread_id} démarre.")
        time.sleep(thread_id)  # Simule une tâche avec un temps de sommeil différent pour chaque thread

        print(f"Thread {thread_id} atteint la barrière.")
        self.barrier.wait()  # Les threads attendent ici jusqu'à ce que tous les threads aient atteint ce point

        # Code à exécuter après que tous les threads ont passé la barrière
        result = f"Resultat du thread {thread_id}"
        
        # Ajout du résultat à la liste partagée via la méthode de la classe
        self.add_result(result)
        
        print(f"Thread {thread_id} continue après la barrière.")

# Nombre de threads
num_threads = 50  # Tu peux changer ce nombre pour tester avec différents nombres de threads
manager = ThreadManager(num_threads)

# Crée et démarre les threads
threads = []
for i in range(num_threads):
    t = threading.Thread(target=manager.worker, args=(i,))
    threads.append(t)
    t.start()

# Attend que tous les threads se terminent
for t in threads:
    t.join()

print("Tous les threads ont terminé.")
print("Résultats collectés:", manager.results)
