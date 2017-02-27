import unittest
import mysort


class MySortTest(unittest.TestCase):
    def test_bubblesort(self):
        l = [1, 6, 4, 2, 5, 3]

        self.assertEqual(
            [1, 2, 3, 4, 5, 6],
            mysort.bubblesort(l)
        )
        self.assertEqual(
            [1, 6, 4, 2, 5, 3],
            l
        )


    def test_bubblesort_from_tuple(self):
        tup = (1, 1, 4, 5, 1, 4)

        self.assertEqual(
            [1, 1, 1, 4, 4, 5],
            mysort.bubblesort(tup)
        )


def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.makeSuite(MySortTest))
    return suite
