# Press the green button in the gutter to run the script.
if __name__ == '__main__':

    class Media:
        def __init__(self, title, ID):
            self.title = title
            self.ID = ID
            self.genre = ""
            self.year = 0
            self.valid = False

        def __str__(self):
            return self.title + "|" + self.ID + "|" + self.genre + "|" + str(self.year)

        def add_data(self, genre, year):
            self.genre = genre
            self.year = year
            self.valid = True

    movies = []
    with open('second_data.tsv', encoding="utf8") as f:
        for i in range(0, 9000000):
            try:
                first_line = f.readline().strip('\n')
                words = first_line.split("\t")

                if(words[3] == 'US'):
                    movies.append(Media(words[2], words[0]))

            except:
                pass;

    count = 0
    with open('data.tsv', encoding="utf8") as f:
        for i in range(0, 9000000):
                first_line = f.readline().strip('\n')
                words = first_line.split("\t")

                if(count < len(movies) and words[0] == movies[count].ID):
                    if(words[8] != '\\N' and words[5] != '\\N' and not words[8].__contains__("Adult")):
                        movies[count].add_data(words[8], words[5])

                    count += 1

                while(count < len(movies) and words[0] > movies[count].ID):
                    count += 1

    file1 = open("MovieData.txt", "w", encoding="utf8")
    for movie in movies:
        if(movie.valid):
            file1.write(str(movie) + "\n")
    file1.close()