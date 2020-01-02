import unittest
import mysort
import random


class MySortTest(unittest.TestCase):
    def test_bubblesort(self):
        alist = [1, 6, 4, 2, 5, 3]

        self.assertEqual(
            [1, 2, 3, 4, 5, 6],
            mysort.bubblesort(alist)
        )
        self.assertEqual(
            [1, 6, 4, 2, 5, 3],
            alist
        )

    def test_bubblesort_from_tuple(self):
        tup = (1, 1, 4, 5, 1, 4)

        self.assertEqual(
            [1, 1, 1, 4, 4, 5],
            mysort.bubblesort(tup)
        )

    def test_bubblesort_very_long_list(self):
        alist = list(range(10000))
        random.shuffle(alist)

        self.assertEqual(
            list(range(10000)),
            mysort.bubblesort(alist)
        )


def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.makeSuite(MySortTest))
    return suite
